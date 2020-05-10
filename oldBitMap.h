#ifndef BIT_MAP_H
#define BIT_MAP_H

#include <string>
#include <fstream>
#include <MyHeaders/Math.h>

using MCL::ceil;
using MCL::floor;
using MCL::pow;
using MCL::min;

typedef unsigned char uchar;

struct Color
{
  uchar Red, Green, Blue;

  Color();
  Color(uchar r, uchar g, uchar b) : Red(r), Green(g), Blue(b){}
  Color& operator=(const Color& c);
  Color& operator+=(const Color& c);
  Color& operator^=(const Color& c);
  const Color& operator+(const Color& c) const;
  const Color& operator^(const Color& c) const;
  const Color& operator/(uchar D) const;
};



struct BMPImg
{
  uint32_t Width;
  uint32_t Height;
  Color* Image;

  BMPImg(uint32_t w, uint32_t h, const Color& Init = Color(0,0,0));
  BMPImg(const BMPImg& img);
  ~BMPImg();
  Color& operator()(uint32_t y, uint32_t x);
  const Color& Read(uint32_t y, uint32_t x) const;
  bool Write(uint32_t y, uint32_t x, const Color& c);
  BMPImg& operator=(const BMPImg& img);
  BMPImg& Resize(uint32_t dy, uint32_t dx);
  BMPImg& Paste(uint32_t y, uint32_t x, const BMPImg& img);
  BMPImg& operator+(const BMPImg& img);
};



struct BitMapFile
{
  const char* MagicBytes = "BM";
  uint32_t Size;
  uint16_t useless0 = 0;
  uint16_t useless1 = 0;
  uint32_t ImgOff = 54;
  uint32_t DIBHeadSize = 40;
  uint32_t Width;
  uint32_t Height;
  uint16_t useless2 = 1;
  uint16_t bpp = 24;
  uint32_t Comp = 0;
  uint32_t BMPDatSize;
  uint32_t ResX;
  uint32_t ResY;
  uint32_t NumColors = 0;
  uint32_t useless3 = 0;

  BMPImg Image;

  //BitMapFile(std::string FileName);
  BitMapFile(const BMPImg& img, uint32_t wRes, uint32_t hRes);
  bool Write(std::string FileName);
};


Color::Color()  //<=> Color(0,0,0) = Black
{
  Red = 0;
  Green = 0;
  Blue = 0;
}
Color& Color::operator=(const Color& c)
{
  Red = c.Red;
  Green = c.Green;
  Blue = c.Blue;
  return *this;
}
Color& Color::operator+=(const Color& c)
{
  Red = Red / 2 + c.Red / 2;
  Green = Green / 2 + c.Green / 2;
  Blue = Blue / 2 + c.Blue / 2;
  return *this;
}
Color& Color::operator^=(const Color& c)
{
  Red = ((Red <= 255 - c.Red) ? Red + c.Red : 255);
  Green = ((Green <= 255 - c.Green) ? Green + c.Green : 255);
  Blue = ((Blue <= 255 - c.Blue) ? Blue + c.Blue : 255);

  return *this;
}
const Color& Color::operator+(const Color& c) const
{
  return Color(Red/2 + c.Red/2, Green/2 + c.Green/2, Blue/2 + c.Blue/2);
}
const Color& Color::operator^(const Color& c) const
{
  return Color(
    ((Red <= 255 - c.Red) ? Red + c.Red : 255),
    ((Green <= 255 - c.Green) ? Green + c.Green : 255),
    ((Blue <= 255 - c.Blue) ? Blue + c.Blue : 255)
  );
}
const Color& Color::operator/(uchar D) const
{
  return Color(Red/D, Green/D, Blue/D);
}




BMPImg::BMPImg(uint32_t w, uint32_t h, const Color& Init) : Width(w), Height(h)
{
  Image = new Color[w*h];  //typeof Image = Color*
  for (unsigned long long int i = 0; i < w*h; i++)
  {
    Image[i] = Init;
  }
}
BMPImg::BMPImg(const BMPImg& img)
{
  Width = img.Width;
  Height = img.Height;
  Image = new Color [Width * Height];

  for (int i = 0; i < Width * Height; i++)
  {
    Image[i] = img.Image[i];
  }
}
BMPImg::~BMPImg()
{
  delete[] Image;
}
Color& BMPImg::operator()(uint32_t y, uint32_t x)
{
  return Image[Width * y + x];
}
const Color& BMPImg::Read(uint32_t y, uint32_t x) const
{
  if (y < Height && x < Width)
    return Image[Width * y + x];
  else
    return Color(255,255,255);
}
bool BMPImg::Write(uint32_t y, uint32_t x, const Color& c)
{
  if (y < Height && x < Width)
  {
    Image[Width * y + x] = c;
    return 1;
  }
  else
    return 0;
}
BMPImg& BMPImg::operator=(const BMPImg& img)
{
  Width = img.Width;
  Height = img.Height;
  delete[] Image;
  Image = new Color [Width * Height];

  for (int i = 0; i < Width * Height; i++)
  {
    Image[i] = img.Image[i];
  }

  return *this;
}
BMPImg& BMPImg::Resize(uint32_t dy, uint32_t dx)
{
  BMPImg Old = *this;
  Width += dx;
  Height += dy;
  delete[] Image;
  Image = new Color[Width * Height];

  this->Paste(0, 0, Old);

  return *this;
}
BMPImg& BMPImg::Paste(uint32_t y, uint32_t x, const BMPImg& img)
{
  for (uint32_t j = 0; j < min(img.Height, Height); j++)
  {
    for (uint32_t i = 0; i < min(img.Width, Width); i++)
    {
      (*this)(j + y, i + x) = img.Read(j, i);
    }
  }

  return *this;
}
BMPImg& BMPImg::operator+(const BMPImg& img)
{
  return this->Paste(0,0,img);
}



std::string IntToCharArr(uint32_t Inp, unsigned int ByteSize, bool End = 0)
{
  //std::cout << "\t" << Inp << " = " << ItoS((unsigned long long)Inp, 16) << ":\n\t";

  std::string Output = "";
  if (End == 0)  //Big-Endian
  {
    for (int i = ByteSize; i > 0; i--)
    {
      Output += (unsigned char)(Inp >> 8*(i - 1));
    }
  }
  else  //Little-Endian
  {
    for (int i = 0; i < ByteSize; i++)
    {
      Output += (uchar)(Inp >> 8*i);
      //std::cout << (int)(unsigned char)(Inp >> 8*i) << " = " << ItoS((unsigned long long)(unsigned char)(Inp >> 8*i), 16) << "; ";
    }
  }
  /*std::cout << "\n\t";

  for (char c : Output)
  {
    std::cout << ItoS((unsigned long long)c, 16) << " ";
  }
  std::cout << "\n\n";*/

  return Output;
}
std::string itca(uint32_t Inp, unsigned int ByteSize, bool End = 0)
{
  return IntToCharArr(Inp, ByteSize, End);
}



/*BitMapFile::BitMapFile(std::string FileName)
{

}//*/
BitMapFile::BitMapFile(
  const BMPImg& img,
  uint32_t wRes,
  uint32_t hRes
) : Image(img), ResX(wRes), ResY(hRes)
{
  Width = img.Width;
  Height = img.Height;
  //std::cout << "Input size: " << img.Width << "x" << img.Height << "\n\n";
  //std::cout << "This image size: " << Width << "x" << Height << "\n\n";
  BMPDatSize = img.Width * img.Height * bpp/8 + (3 - (Image.Width - 1) % 4)*img.Height;
  Size = 2 + 4 + 2 + 2 + 4 + DIBHeadSize + BMPDatSize;
}

bool BitMapFile::Write(std::string FileName)
{
  std::ofstream File(FileName, std::ios_base::binary | std::ios_base::out);
  if (!File.is_open())
    return 0;

  File.write("BM", 2); //0x0
  File.write(itca(Size, 4, 1).c_str(), 4); //0x2
  File.write("\x00\x00\x00\x00", 4); //0x6
  File.write(itca(ImgOff, 4, 1).c_str(), 4); //0xA

  File.write(itca(DIBHeadSize, 4, 1).c_str(), 4); //0xE
  File.write(itca(Width, 4, 1).c_str(), 4); //0x12
  File.write(itca(Height, 4, 1).c_str(), 4); //0x16
  File.write("\x01\x00", 2); //0x1A; //0x1B
  File.write(itca(bpp, 2, 1).c_str(), 2);
  File.write(itca(Comp, 4, 1).c_str(), 4);
  File.write(itca(BMPDatSize, 4, 1).c_str(), 4);
  File.write(itca(ResX, 4, 1).c_str(), 4);
  File.write(itca(ResY, 4, 1).c_str(), 4);
  File.write(itca(NumColors, 4, 1).c_str(), 4);
  File.write("\x00\x00\x00\x00", 4);

  //std::cout << "Padding/Line = " << 3 - (Image.Width - 1) % 4 << "\n\n";

  for (int j = Image.Height-1; j >= 0; j--)
  {
    for (int i = 0; i < Image.Width; i++)
    {
      File.write(itca(Image(j,i).Blue,1,1).c_str(), 1);
      File.write(itca(Image(j,i).Green,1,1).c_str(), 1);
      File.write(itca(Image(j,i).Red,1,1).c_str(), 1);
    }

    File.write("\x00\x00\x00", 3 - (Image.Width - 1) % 4);
  }

  File.close();

  return 1;
}


#endif
