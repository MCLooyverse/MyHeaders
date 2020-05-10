#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

#include <MyHeaders/Math.h>
#include <string>
#include <MyHeaders/strmanip.h>


struct Complex
{
  double R;
  double I;

  Complex(Complex z) : R(z.R), I(z.I) {}
  Complex(double a, double b) : R(a), I(b) {}
  Complex(double a) : R(a), I(0) {}
  Complex() : R(0), I(0) {}

  Complex& operator=(Complex z);
  Complex& operator=(double x);

  Complex operator*(Complex z);
  Complex operator*(double x);
  Complex operator+(Complex z);
  Complex operator+(double x);
  Complex operator/(Complex z);
  Complex operator/(double x);
  Complex operator-(Complex z);
  Complex operator-(double x);

  Complex operator%(Complex z);
  Complex operator%(double x);

  Complex& operator*=(Complex z);
  Complex& operator*=(double x);
  Complex& operator+=(Complex z);
  Complex& operator+=(double x);
  Complex& operator/=(Complex z);
  Complex& operator/=(double x);
  Complex& operator-=(Complex z);
  Complex& operator-=(double x);

  bool operator==(Complex z);
  bool operator!=(Complex z);

  Complex conj();

  std::string str() const;
};



double abs(Complex z)
{
  return MCL::root(2, MCL::pow(z.R, (llint)2) + MCL::pow(z.I, (llint)2));
}

Complex cis(double theta)
{
  return Complex(MCL::cos(theta), MCL::sin(theta));
}

Complex pow(Complex z, llint n)
{
  Complex Output(1);
  for (llint c = 0; c < n; c++)
  {
    Output *= z;
  }

  return Output;
}





Complex& Complex::operator=(Complex z)
{
  R = z.R;
  I = z.I;
  return *this;
}
Complex& Complex::operator=(double x)
{
  R = x;
  I = 0;
  return *this;
}

Complex Complex::operator*(Complex z)
{
  //(a + bi) * (c + di) = ac + adi + bci + bdii = ac - bd + (ad + bc)i
  return Complex(R * z.R - I * z.I, R * z.I + I * z.R);
}
Complex Complex::operator*(double x)
{
  return Complex(R * x, I * x);
}
Complex Complex::operator+(Complex z)
{
  return Complex(R + z.R, I + z.I);
}
Complex Complex::operator+(double x)
{
  return Complex(R + x, I);
}
Complex Complex::operator/(Complex z)
{
  return *this * z.conj() / (z.R * z.R + z.I * z.I);
}
Complex Complex::operator/(double x)
{
  return Complex(R / x, I / x);
}
Complex Complex::operator-(Complex z)
{
  return Complex(R - z.R, I - z.I);
}
Complex Complex::operator-(double x)
{
  return Complex(R - x, I);
}

Complex Complex::operator%(Complex z)
{
  return *this - floor(*this / z) * z;
}
Complex Complex::operator%(double x)
{
  return Complex(MCL::mod(R, x), MCL::mod(I, x));
}

Complex& Complex::operator*=(Complex z)
{
  //(a + bi) * (c + di) = ac + adi + bci + bdii = ac - bd + (ad + bc)i
  double OldR = R;
  R = R * z.R - I * z.I;
  I = OldR * z.I + I * z.R;
  return *this;
}
Complex& Complex::operator*=(double x)
{
  R *= x;
  I *= x;
  return *this;
}
Complex& Complex::operator+=(Complex z)
{
  R += z.R;
  I += z.I;
  return *this;
}
Complex& Complex::operator+=(double x)
{
  R += x;
  return *this;
}
Complex& Complex::operator/=(Complex z)
{
  *this = *this / z;
  return *this;
}
Complex& Complex::operator/=(double x)
{
  R /= x;
  I /= x;
  return *this;
}
Complex& Complex::operator-=(Complex z)
{
  R -= z.R;
  I -= z.I;
  return *this;
}
Complex& Complex::operator-=(double x)
{
  R -= x;
  return *this;
}

bool operator==(Complex z)
{
  return R == z.R && I == z.I;
}
bool operator!=(Complex z)
{
  return R != z.R || I != z.I;
}

Complex Complex::conj()
{
  return Complex(R, -I);
}

std::string Complex::str() const
{
  if (I == 0)
    return DtoS(R);
  else if (I < 0)
    return (DtoS(R) + " - " + DtoS(-I) + "i");
  else
    return (DtoS(R) + " + " + DtoS(I) + "i");
}



operator Complex(unsigned long long int x)
{
  return Complex(x);
}
operator Complex(long long int x)
{
  return Complex(x);
}
operator Complex(double x)
{
  return Complex(x);
}



Complex floor(Complex z)
{
  return Complex(MCL::floor(z.R), MCL::floor(z.I));
}

Complex mod(Complex a, Complex b)
{
  return a % b;
}
Complex mod(Complex z, double x)
{
  return z % x;
}
Complex mod(double x, Complex z)
{
  return x - floor(x / z) * z;
}

#endif
