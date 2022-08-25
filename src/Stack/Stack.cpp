#include "../Vector/Vector.cpp"

template<typename T>
class Stack : public Vector<T> {
 public:
  auto push(T const &e) {
	insert(e);
  }

  auto pop() {
	return remove(size() - 1);
  }

  auto top() {
	return (*this)[size() - 1];
  }
};