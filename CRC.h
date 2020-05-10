#ifndef MCL_CRC_H
#define MCL_CRC_H


char* CRC_n(uint BitCount, const char* str, ullint len, const uchar* polynomial)  //Assume x^n term in polynomial
{
  if (BitCount == 0)
    return 0;

  const usint bCResidue = (BitCount + 7) % 8 + 1;
  const usint ByteCount = BitCount / 8 + (bCResidue != 8);

  char* Copy = new char[len];
  for (ullint i = 0; i < len; i++)
    Copy[i] = str[i];

  if (len <= ByteCount)
    return Copy;


  ullint ByteShift = 0;
  uchar BitShift = 7;

  uchar Front = 0b10000000;

  while (1)
  {
    while ((Copy[ByteShift] & Front) == 0)
    {
      --BitShift;
      if ((Front >>= 1) == 0)
      {
        BitShift = 7;
        Front = 0x80;
        ++ByteShift;
      }
      if ((ByteShift == len - ByteCount) && (BitShift < bCResidue))
        return Copy;
    }

    Copy[ByteShift] ^= Front ^ MCL::SHL(polynomial[0], (llint)BitShift - bCResidue);
    for (uint i = 1; i < ByteCount; i++)
      Copy[ByteShift+i] ^= (polynomial[i-1] << (8 - bCResidue + BitShift)) ^ MCL::SHL(polynomial[i], (llint)BitShift - bCResidue);
    Copy[ByteShift+ByteCount] ^= (polynomial[ByteCount-1] << (8 - bCResidue + BitShift));
  }
}


#endif
