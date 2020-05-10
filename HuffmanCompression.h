#ifndef HUFFMAN_COMPRESSION_H
#define HUFFMAN_COMPRESSION_H

#include <MyHeaders/ListSorting.h>
#include <MyHeaders/strmanip.h>

#include <cstdlib> //malloc because FUCK you.

typedef unsigned short int usint;

char* HuffComp(const char* msg, uint16_t len)
{
  if (len == 0)
    return 0;


  uint16_t* ByteFreq = new uint16_t[256];
  if (ByteFreq == 0)
  {
    std::cout << "WHAT IN THE ENTIRE FUCKING FUCK";
    exit(-10000);
  }
  usint DistinctBytes = 0;

  for (unsigned int i = 0; i < len; i++)
  {
    if (ByteFreq[msg[i]]++ == 0)
      ++DistinctBytes;
  }

  std::cout << "Got character counts.  " << (int)DistinctBytes << " Distinct characters.\n";

  if (DistinctBytes == 1)
  {
    //Can't be bothered
  }

  char* CharFreqPairs = new char[DistinctBytes * 3];
  if (CharFreqPairs == 0)
  {
    std::cout << "BOI";
    exit(-100);
  }
  char* p = CharFreqPairs;
  for (unsigned int i = 0; i < 256; i++)
  {
    if (ByteFreq[i] != 0)
    {
      *(p++) = i;
      *((uint16_t*)p) = ByteFreq[i];
      p += 2;
    }
  }
  delete[] ByteFreq;

  std::cout << "Removed reference to non-present chars.\n";

  usint* Groups = new usint[DistinctBytes + 1];
  std::cout << "Dumbass?\n";
  std::cout.flush();
  return 0;
  if (CharFreqPairs == 0)
  {
    std::cout << "BOI";
    exit(-100);
  }
  for (unsigned int i = 0; i < DistinctBytes; i++)
    Groups[i] = 1;
  Groups[DistinctBytes] = 0;
  char* Buffer = new char[DistinctBytes * 3];
  usint* WriteGroup = Groups;
  bool Swap = 0;

  while (Groups[0] != DistinctBytes)
  {
    std::cout << "Sorting list... Groups: { ";
    for (unsigned int i = 0; i < DistinctBytes; i++)
      std::cout << (unsigned int)Groups[i] << ", ";
    std::cout << "\b\b }\n";
    Swap = !Swap;
    p = Buffer;
    for (uint16_t g = 0, k = 0, l = Groups[0], m = Groups[1]; Groups[g+1] != 0; g += 2, k = m, l = m + Groups[g], m += Groups[g] + Groups[g+1])
    {
      *(WriteGroup++) = l + m - k;
      *WriteGroup = 0;
      uint16_t i = k, j = l;
      for ( ; i < l && j < m; )
      {
        if (*((uint16_t*)(CharFreqPairs + 3 * i + 1)) > *((uint16_t*)(CharFreqPairs + 3 * i + 1)))
        {
          *(p++) = *((uint16_t*)(CharFreqPairs + 3 * j));
          *(p++) = *((uint16_t*)(CharFreqPairs + 3 * j + 1));
          *(p++) = *((uint16_t*)(CharFreqPairs + 3 * j + 2));
        }
        else
        {
          *(p++) = *((uint16_t*)(CharFreqPairs + 3 * i));
          *(p++) = *((uint16_t*)(CharFreqPairs + 3 * i + 1));
          *(p++) = *((uint16_t*)(CharFreqPairs + 3 * i + 2));
        }
      }
      while (i < l)
      {
        *(p++) = *((uint16_t*)(CharFreqPairs + 3 * i));
        *(p++) = *((uint16_t*)(CharFreqPairs + 3 * i + 1));
        *(p++) = *((uint16_t*)(CharFreqPairs + 3 * i + 2));
      }
      while (j < m)
      {
        *(p++) = *((uint16_t*)(CharFreqPairs + 3 * j));
        *(p++) = *((uint16_t*)(CharFreqPairs + 3 * j + 1));
        *(p++) = *((uint16_t*)(CharFreqPairs + 3 * j + 2));
      }
    }

    char* Intermediate = CharFreqPairs;
    CharFreqPairs = Buffer;
    Buffer = Intermediate;
  }

  if (Swap)
  {
    for (uint16_t i = 0; i < DistinctBytes * 3; i++)
      CharFreqPairs[i] = Buffer[i];
  }


  for (uint16_t i = 0; i < DistinctBytes * 3; i += 3)
  {
    std::cout << NVCtoHexRep((unsigned char)CharFreqPairs[i]) << ":" << *(uint16_t*)(CharFreqPairs + i + 1) << "\n";
  }


  return 0;
}


#endif
