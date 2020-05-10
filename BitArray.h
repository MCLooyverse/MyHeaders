#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <MyHeaders/Math.h>

typedef uint8_t byte;
typedef unsigned long long int ullint;
typedef unsigned int uint;

struct BitArray
{
private:
  byte* arr;
  unsigned int size;
  ullint bsize;

public:
  BitArray(ullint BitCount)
  {
    size = BitCount / 8 + (bool)(BitCount % 8);
    bsize = BitCount;
    arr = new byte(0)[size];
  }
  ~BitArray()
  {
    delete[] arr;
  }
  bool operator[](ullint Index)
  {
    return arr[Index / 8] & (0x80 >> (Index % 8));
  }
  BitArray& write(ullint Index, bool Val)
  {
    /*byte b = arr[Index/8];
    if (Val)
      b = ~b; //Eqivalent to `b ^= Val * 0xFF`, but maybe faster
    b |= (byte)(0x80 >> (Index % 8));
    if (Val)
      b = ~b;

    arr[Index/8] = b;*/

    (arr[Index/8] &= ~(0x80 >> (Index % 8))) |= Val * (0x80 >> (Index % 8));

    return *this;
  }
  template <class T>
  BitArray& write(ullint Index, T Container, ullint BitCount = 8 * sizeof(T), bool AlignRight = 0)
  {
    if (AlignRight)
    {
      if (bsize < Index + BitCount)
      {

      }
    }
    else
    {
      ullint End = MCL::min()
    }
  }
  bool read(ullint Index)
  {
    return arr[Index / 8] & (0x80 >> (Index % 8));
  }
  byte* read(ullint Index, ullint Count = bsize)
  {
    byte* Output = new byte(0)[Count];
    ullint End = ((bsize < Index + Count) ? bsize - Index : Count);
    byte Mask = 0xFF >> (Index % 8);
    for (uint i = 0; i < End; i++)
    {
      
    }
  }
};


#endif
