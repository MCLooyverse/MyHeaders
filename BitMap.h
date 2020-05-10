#ifndef BIT_MAP_H
#define BIT_MAP_H

#include <string>
#include <fstream>
#include <MyHeaders/TypeMath.h>


typedef uint8_t byte;


struct Pixel
{
  union {
    uint32_t ABGR;
    struct {
      byte A, B, G, R;
    };
  };

  Pixel() : ABGR(0xFFFFFFFF) { }
  Pixel(uint32_t abgr) : ABGR(abgr) { }
  Pixel(byte r, byte g, byte b, byte a = 0xFF) : R(r), G(g), B(b), A(a) { }
  Pixel& operator+=(const Pixel& p);
  Pixel& operator^=(const Pixel& p);
  Pixel& operator/=(byte d);
  const Pixel& operator+(const Pixel& p) const;
  const Pixel& operator^(const Pixel& p) const;
  const Pixel& operator/(byte d) const;
};




Pixel& Pixel::operator+=(const Pixel& p)
{
  R = ((int)R + p.R) / 2;
  G = ((int)G + p.G) / 2;
  B = ((int)B + p.B) / 2;
  return *this;
}
Pixel& Pixel::operator^=(const Pixel& p)
{
  R = (R <= 255 - p.R ? R + p.R : 255);
  G = (G <= 255 - p.G ? G + p.G : 255);
  B = (B <= 255 - p.B ? B + p.B : 255);
  return *this;
}
Pixel& Pixel::operator/=(byte d)
{
  R /= d;
  G /= d;
  B /= d;
  return *this;
}
const Pixel& Pixel::operator+(const Pixel& p) const
{
  return Pixel(((int)R + p.R) / 2, ((int)G + p.G) / 2, ((int)B + p.B) / 2, ((int)A + p.A) / 2);
}
const Pixel& operator^(const Pixel& p) const
{
  return Pixel(R <= 255 - p.R ? R + p.R : 255, )
}
const Pixel& operator/(byte d) const;
