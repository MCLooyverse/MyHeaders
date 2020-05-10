#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include <MyHeaders/strmanip.h>

typedef unsigned int uint;


template <class T>
T Dot(T* a, T* b, uint size)
{
  T Output = 0;
  for (uint i = 0; i < size; i++)
    Output += a[i] * b[i];
  return Output;
}
template <class T>
T Dot(std::vector<T> a, std::vector<T> b)
{
  T Output = 0;
  uint Max = a.size();
  if (a.size() > b.size())
    Max = b.size();
  for (uint i = 0; i < Max; i++)
    Output += a[i] * b[i];
  return Output;
}


enum MatrixErr {
  SizeMismatch
};


template <class N>
class Matrix
{
private:
  N* Ptr;//Stored with each row after the other
  uint Height;
  uint Width;

public:
  Matrix(uint, uint);
  Matrix(const Matrix<N>&);
  Matrix(N*, uint, uint = 1);
  Matrix(std::vector<N>, uint = 1);
  Matrix(std::string);
  ~Matrix();

  Matrix& operator=(const Matrix<N>&);
  Matrix& operator=(std::vector<N>);

  Matrix<N>& FromStr(std::string);
  std::string ToILStr() const;
  std::string ToMLStr() const;

  operator std::string() const;


  std::vector<N> Row(uint) const;
  std::vector<N> Col(uint) const;
  const Matrix<N> T() const;  //Transpose
  const Matrix I() const;  //Inverse

  N& operator()(uint, uint);
  N Get(uint, uint) const;
  const Matrix<N> operator+(const Matrix<N>&) const;
  const Matrix<N> operator-(const Matrix<N>&) const;
  template <class T> const Matrix<N> operator*(T scalar) const
  {
    Matrix<N> Output(Height, Width);
    for (uint i = 0; i < Height; i++)
    {
      for (uint j = 0; j < Width; j++)
        Output(i, j) = Ptr[i * Width + j] * scalar;
    }
    return Output;
  }
  template <class T> Matrix<N>& operator*=(T scalar)
  {
    for (uint i = 0; i < Height * Width; i++)
      Ptr[i] *= scalar;
    return *this;
  }
  template<class T> friend const Matrix<N> operator*(T, const Matrix<N>&);
  const Matrix<N> operator*(const Matrix<N>&) const;
  template <class T> const Matrix<N> operator/(T scalar) const
  {
      Matrix<N> Output(Height, Width);
      for (uint i = 0; i < Height; i++)
      {
        for (uint j = 0; j < Width; j++)
          Output(i, j) = Ptr[i * Width + j] / scalar;
      }
      return Output;
  }
  N Dot(const Matrix<N>&) const;
  friend N Dot(const Matrix<N>&, const Matrix<N>&);

  bool operator==(const Matrix<N>&) const;
};



template <class N>
Matrix<N>::Matrix(uint h, uint w) : Height(h), Width(w)
{
  Height = h;
  Width = w;
  Ptr = new N[h * w];
}
template <class N>
Matrix<N>::Matrix(const Matrix<N>& A) : Height(A.Height), Width(A.Width)
{
  Ptr = new N[Height * Width];
  for (uint i = 0; i < Height * Width; i++)
  {
    Ptr[i] = A.Ptr[i];
  }
}
template <class N>
Matrix<N>::Matrix(N* arr, uint h, uint w) : Height(h), Width(w)
{
  Ptr = new N[h * w];
  for (uint i = 0; i < h * w; i++)
    Ptr[i] = arr[i];
}
template <class N>
Matrix<N>::Matrix(std::vector<N> v, uint w) : Height(v.size() / w), Width(w)
{
  Ptr = new N[Height * Width];
  for (uint i = 0; i < v.size(); i++)
    Ptr[i] = v[i];
}
template <class N>
Matrix<N>::Matrix(std::string str)
{
  //Later
}
template <class N>
Matrix<N>::~Matrix()
{
  delete[] Ptr;
}

template <class N>
Matrix<N>& Matrix<N>::operator=(const Matrix<N>& A)
{
  //std::cout << "Assigning " << A.ToILStr() << "\n\n";
  Height = A.Height;
  Width = A.Width;
  delete[] Ptr;
  //std::cout << "Old deleted.\n\n";
  Ptr = new N[Height * Width];
  //std::cout << "New allocated.\n\n";
  for (uint i = 0; i < Height * Width; i++)
    Ptr[i] = A.Ptr[i];
  //std::cout << "Loop finished.\n\n";
  return *this;
}
template <class N>
Matrix<N>& Matrix<N>::operator=(std::vector<N> v)
{
  Height = v.size();
  Width = 1;
  delete[] Ptr;
  Ptr = new N[Height];
  for (uint i = 0; i < Height; i++)
    Ptr[i] = v[i];
  return *this;
}

template <class N>
Matrix<N>& Matrix<N>::FromStr(std::string)
{
  //Something
  return *this;
}
template <class N>
std::string Matrix<N>::ToILStr() const //Inline
{
  std::string Output = "{ ";
  for (uint i = 0; i < Height; i++)
    Output += VtoS(Ptr + (i * Width), Width) + ", ";
  return Output.erase(Output.length() - 2) + " }";
}
template <class N>
std::string Matrix<N>::ToMLStr() const //Multiline
{
  //std::cout << "Running ToMLStr on " << this->ToILStr() << "\n\n";
  uint MaxWidth0 = 0;
  uint MaxWidth = 0;
  std::ostringstream SS;
  uint Old = 0;
  for (uint i = 0; i < Width * Height; i++)
  {
    //std::cout << "Putting " << Ptr[i] << " into stream.\n";
    SS << Ptr[i];
    //std::cout << "good\n";
    if (i % Width)
    {
      if ((uint)SS.tellp() - Old > MaxWidth)
        MaxWidth = (uint)SS.tellp() - Old;
      Old = SS.tellp();
    }
    else
    {
      if ((uint)SS.tellp() - Old > MaxWidth0)
        MaxWidth0 = (uint)SS.tellp() - Old;
      //std::cout << "MaxWidth0 = " << MaxWidth0 << "\n";
      Old = SS.tellp();
    }
  }
  std::string Output = "";
  SS.str("");
  SS << Ptr[0];
  if (Height == 1)
  {
    Output = "[ " + std::string(MaxWidth0 - SS.tellp(), ' ') + SS.str() + "  ";
    //std::cout << "good\n";
    for (uint i = 1; i < Width; i++)
    {
      SS.str("");
      SS << Ptr[i];
      Output += std::string(MaxWidth - SS.tellp(), ' ') + SS.str() + "  ";
      //std::cout << "good\n";
    }
    Output.back() = ']';
    return Output;
  }
  Output = /*"\u250C "*/"/ " + std::string(MaxWidth0 - SS.tellp(), ' ') + SS.str() + "  ";
  for (uint i = 1; i < Width; i++)
  {
    SS.str("");
    SS << Ptr[i];
    Output += std::string(MaxWidth - SS.tellp(), ' ') + SS.str() + "  ";
  }
  //Output.replace(Output.length() - 1, 1, "\u2510");
  Output.back() = '\\';
  Output += '\n';
  for (uint i = 1; i < Height - 1; i++)
  {
    SS.str("");
    SS << Ptr[i * Width];
    Output += /*"\u2502 "*/"| " + std::string(MaxWidth0 - SS.tellp(), ' ') + SS.str() + "  ";
    for (uint j = 1; j < Width; j++)
    {
      SS.str("");
      SS << Ptr[i * Width + j];
      Output += std::string(MaxWidth - SS.tellp(), ' ') + SS.str() + "  ";
    }
    //Output.replace(Output.length() - 1, 1, "\u2502");
    Output.back() = '|';
    Output += '\n';
  }
  SS.str("");
  SS << Ptr[(Height - 1) * Width];
  Output += /*"\u2514 "*/"\\ " + std::string(MaxWidth0 - SS.tellp(), ' ') + SS.str() + "  ";
  for (uint i = 1; i < Width; i++)
  {
    SS.str("");
    SS << Ptr[(Height - 1) * Width + i];
    Output += std::string(MaxWidth - SS.tellp(), ' ') + SS.str() + "  ";
  }
  //Output.replace(Output.length() - 1, 1, "\u2518");
  Output.back() = '/';
  return Output;
}

template <class N>
Matrix<N>::operator std::string() const
{
  std::string Output = "{ ";
  for (uint i = 0; i < Height; i++)
    Output += VtoS(Ptr + (i * Width), Width) + ", ";
  return Output.erase(Output.length() - 2) + " }";
}


template <class N>
std::vector<N> Matrix<N>::Row(uint h) const
{
  std::vector<N> Output(Width);
  for (uint i = 0; i < Width; i++)
    Output[i] = Ptr[Width * h + i];
  return Output;
}
template <class N>
std::vector<N> Matrix<N>::Col(uint w) const
{
  std::vector<N> Output(Height);
  for (uint i = 0; i < Height; i++)
    Output[i] = Ptr[i * Width + w];
  return Output;
}
template <class N>
const Matrix<N> Matrix<N>::T() const //Transpose
{
  Matrix<N> Output(Width, Height);
  for (uint i = 0; i < Height; i++)
  {
    for (uint j = 0; j < Width; j++)
      Output(j, i) = Ptr[i * Width + j];
  }
  return Output;
}
template <class N>
const Matrix<N> Matrix<N>::I() const  //Inverse
{
  //Later
}

template <class N>
N& Matrix<N>::operator()(uint row, uint col)
{
  return Ptr[row * Width + col];
}
template <class N>
N Matrix<N>::Get(uint row, uint col) const
{
  return Ptr[row * Width + col];
}
template <class N>
const Matrix<N> Matrix<N>::operator+(const Matrix<N>& A) const
{
  if (Height != A.Height || Width != A.Width)
  {
    throw(SizeMismatch);
    return Matrix((uint)0,0);
  }

  Matrix<N> Output(Height, Width);
  for (uint i = 0; i < Height; i++)
  {
    for (uint j = 0; j < Width; j++)
      Output(i, j) = Ptr[i * Width + j] + A.Get(i, j);
  }
  return Output;
}
template <class N>
const Matrix<N> Matrix<N>::operator-(const Matrix<N>& A) const
{
  if (Height != A.Height || Width != A.Width)
  {
    throw(SizeMismatch);
    return Matrix((uint)0,0);
  }

  Matrix<N> Output(Height, Width);
  for (uint i = 0; i < Height; i++)
  {
    for (uint j = 0; j < Width; j++)
      Output(i, j) = Ptr[i * Width + j] - A(i, j);
  }
  return Output;
}
template<class N, class T>
const Matrix<N> operator*(T scalar, const Matrix<N>& A)
{
  Matrix<N> Output(A.Height, A.Width);
  for (uint i = 0; i < A.Height; i++)
  {
    for (uint j = 0; j < A.Width; j++)
      Output(i, j) = A.Ptr[i * A.Width + j] * scalar;
  }
  return Output;
}
template <class N>
const Matrix<N> Matrix<N>::operator*(const Matrix<N>& A) const
{
  if (Width != A.Height)
  {
    throw(SizeMismatch);
    return Matrix((uint)0,0);
  }

  //std::cout << "Multiplying:\n";// << this->ToILStr() << A.ToILStr() << "\n";
  //std::cout << StitchLines(this->ToMLStr(), A.ToMLStr(), 0b101) << "\n\n";

  Matrix<N> Output(Height, A.Width);
  for (uint i = 0; i < Height; i++)
  {
    for (uint j = 0; j < A.Width; j++)
    {
      Output(i, j) = ::Dot(this->Row(i), A.Col(j));
      //std::cout << "Dot(" << VtoS(this->Row(i)) << ", " << VtoS(A.Col(j)) << ") = " << Output(i, j) << "\n";
    }
  }
  //std::cout << "Result:\n" << Output.ToMLStr() << "\n\n";
  return Output;
}
template <class N>
N Matrix<N>::Dot(const Matrix<N>& A) const
{
  if (Height != A.Height || Width != A.Width)
  {
    throw(SizeMismatch);
    return 0;
  }

  N Output = 0;
  for (uint i = 0; i < Height; i++)
  {
    for (uint j = 0; j < Width; j++)
      Output += Ptr[i * Width + j] * A(i, j);
  }
  return Output;
}
template <class N>
N Dot(const Matrix<N>& A, const Matrix<N>& B)
{
  if (A.Height != B.Height || A.Width != B.Width)
  {
    throw(SizeMismatch);
    return 0;
  }

  N Output = 0;
  for (uint i = 0; i < A.Height; i++)
  {
    for (uint j = 0; j < A.Width; j++)
      Output += A(i, j) * B(i, j);
  }
  return Output;
}

template <class N>
bool Matrix<N>::operator==(const Matrix<N>& A) const
{
  if (Height != A.Height || Width != A.Width)
    return 0;
  for (uint i = 0; i < Width * Height; i++)
  {
    if (Ptr[i] != A.Ptr[i])
      return 0;
  }
  return 0;
}


#endif
