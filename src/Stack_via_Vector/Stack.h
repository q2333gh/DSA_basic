
#ifndef _Stack_H
#define _Stack_H
#include "../Vector/Vector.h"
template <typename T> class Stack : public Vector<T> {
public:
  auto push(T const &e) { Vector<T>::insert(e); }
  T pop() { return Vector<T>::remove(Vector<T>::size() - 1); }
  T &top() { return (*this)[Vector<T>::size() - 1]; }
  bool empty() {
    bool b = !(Vector<T>::size());
    return b;
  }
};





#endif
