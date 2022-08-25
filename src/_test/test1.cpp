//
// Created by 白桃乌龙 on 2022/8/25.
//

#include "test1.h"
#include <iostream>
class base {
protected:
  auto ptd() { return true; }

private:
  auto priv() { return true; }

public:
  auto pub() {
	for (int i = 0; i < 20; i++) {
	  std::cout << "test";
	}
	return true;
  }
};
class deriv : public base {
  void test() { ptd(); }
  void t2() { pub(); }
};