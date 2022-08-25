//
// Created by 白桃乌龙 on 2022/8/25.
//

#ifndef DSA_NEW_SRC_QUEUE_QUEUE_H_
#define DSA_NEW_SRC_QUEUE_QUEUE_H_
#include "../List/List.h"
template <typename T> class Queue : public List<T> {
public:
  auto enqueue(T const &e) { return List<T>::insertAsLast(e); }
  auto front() { return List<T>::first()->data; }
  auto dequeue() { return List<T>::remove(List<T>::first()); }
  auto rear() { return List<T>::last()->data; }
  auto printQ(){
    return List<T>::printL();
  }
};

#endif // DSA_NEW_SRC_QUEUE_QUEUE_H_
