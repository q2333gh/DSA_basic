#include "List/List.h"
#include "Stack_via_Vector/Stack.h"
#include "Stack_app/cast.h"
#include <iostream>
struct test {
  auto t1() {
	Stack<int> s1;
	Stack<int> s2;
	for (int i = 0; i < 5; i++) {
	  s1.push(i);
	}
	std::cout<<"s1: if empty  "<<s1.empty();
	std::cout<<"s2: if empty  "<<s2.empty();
	for (int i = 0; i < 5; i++) {
	  std::cout << s1.pop() << " ";
	}

  }
  auto t2(){
	cast<int> c1;
	Vector<int> v1 = c1.toBin(5328);
	v1.printV();
  }
};
int main(int argc, char *argv[]) {

  test t;
//  t.t1();
t.t2();
  return 0;
}

