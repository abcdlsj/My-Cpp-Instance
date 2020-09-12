#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {
protected:
  Rank _size;
  int _capacity;
  *T _elem;
  void copyFron(T const *A, Rank low, Rank hign);
  void expand();
  void shrink();
  void bubble(Rank low, Rank hign);
};

#endif //__VECTOR_H__