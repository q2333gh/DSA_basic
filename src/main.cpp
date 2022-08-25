#include "List/List.h"
#include "Queue/Queue.h"
#include "Stack_app/cast.h"
#include "Stack_via_Vector/Stack.h"
#include "windows.h"
#include <iostream>
struct test {
  auto t1() {
    Stack<int> s1;
    Stack<int> s2;
    for (int i = 0; i < 5; i++) {
      s1.push(i);
    }
    std::cout << "s1: if empty  " << s1.empty();
    std::cout << "s2: if empty  " << s2.empty();
    for (int i = 0; i < 5; i++) {
      std::cout << s1.pop() << " ";
    }
  }
  auto t2() {
    cast<int> c1;
    Vector<int> v1 = c1.toBin(5328);
    v1.printV();
  }
  auto t3() {
    Queue<int> q;
    for (int i = 0; i < 5; i++) {
      q.enqueue(i);
    }
    std::cout << q.front() << " " << q.rear() << "\n";
    for (int i = 0; i < 5; i++) {
      std::cout << q.dequeue() << " ";
    }
  }
  auto t4() {
    Queue<int> Q;
    for (int i = 0; i < 5; i++) {
      Q.enqueue(i);
    }
    for (int i = 0; i < 200; i++) {
      auto e=Q.dequeue();
      std::cout << "running pid: "<<e<<"  |  ";
      Q.enqueue(e);
      Sleep(500);
      Q.printQ();
      std::cout<<std::flush;
    }

  }
};
int main(int argc, char *argv[]) {

  test t;
  //  t.t1();
  // t.t2();
  //  t.t3();
  t.t4();
  return 0;
}
