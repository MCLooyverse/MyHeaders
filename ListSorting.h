#ifndef LIST_SORTING_H
#define LIST_SORTING_H


template <class T> void MergeSort(T* List, unsigned long long int len)
{
  if (len == 1)
    return;

  unsigned long long int Len0 = len >> 1, Len1 = len - Len0;
  MergeSort(List, Len0);
  MergeSort(List+Len0, Len1);
  T* Copy = new T[len];
  for (unsigned long long int i = 0; i < len; i++)
    Copy[i] = List[i];
  unsigned long long int i = 0, j = Len0;
  T* p = List;
  for ( ; i < Len0 && j < len; )
  {
    if (Copy[i] > Copy[j])
      *(p++) = Copy[j++];
    else
      *(p++) = Copy[i++];
  }
  while (i < Len0)
    *(p++) = Copy[i++];
  while (j < len)
    *(p++) = Copy[j++];
  delete[] Copy;
  return;
}


#endif
