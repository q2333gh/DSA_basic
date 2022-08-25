//
// Created by 白桃乌龙 on 2022/8/25.
//

#ifndef DSA_NEW_SRC_STACK_APP_CAST_H
#define DSA_NEW_SRC_STACK_APP_CAST_H
#include "../Stack_via_Vector/Stack.h"
template<typename T>
class cast {
 public:
  auto toBin(T e) {
	Stack<T> s;
	while (e > 0) {
	  s.push(e % 2);
	  e /= 2;
	}
	Vector<T> v;
	while (!s.empty()) {
//      v.insert(0, s.pop());
	  v.insert(s.pop());
	}
	return v;
  }
};

#endif // DSA_NEW_SRC_STACK_APP_CAST_H
