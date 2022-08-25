//
// Created by 白桃乌龙 on 2022/8/23.
//

#ifndef DSA_IMPL_LIST_CPP
#define DSA_IMPL_LIST_CPP

#include "ListNode.cpp"
#include "iostream"

template<typename T>
static bool lt(T *a, T *b) { return lt(*a, *b); } //less than
template<typename T>
static bool lt(T &a, T &b) { return a < b; } //less than
template<typename T>
class List {
private:
  int _size{};
  ListNodePosi<T> header;
  ListNodePosi<T> trailer;
protected:
  void init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = nullptr;
	trailer->pred = header;
	trailer->succ = nullptr;
	_size = 0;
//        std::cout << "list inited";
  }

public:
  T &operator[](Rank r) const {
	ListNode<T> p = first();
	while (0 < r--)
	  p = p.succ;
	return p.data;
  }

  List() { init(); }

  int clear() {
	int oldSize = _size;
	while (0 < _size)
	  remove(header->succ);
	return oldSize;
  }

  ~List() {
	clear();
	delete header;
	delete trailer;
//        std::cout << "list deconstructed.";
  }

  T remove(ListNodePosi<T> p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
  }

  [[nodiscard]] Rank size() const { return _size; }

  [[nodiscard]] bool empty() const { return _size <= 0; }

  ListNodePosi<T> first() const { return header->succ; }

  ListNodePosi<T> find(T const &e, int n, ListNodePosi<T> p) const {
	while (0 < n--) {
	  if (e == (p = p->pred)->data) {
		return p;
	  }
	}
	return nullptr;
  }

  ListNodePosi<T> find(T const &e, ListNodePosi<T> p, int n) const {
	while (0 < n--) {
	  if (e == (p = p->succ)->data) {
		return p;
	  }
	}
	return nullptr;
  }

  auto insertAsFirst(T const &e) {
	_size++;
	return header->insertAsSucc(e);
  }

  auto insertAsLast(T const &e) {
	_size++;
	return trailer->insertAsPred(e);
  }

  auto copyNodes(ListNodePosi<T> p, int n) {
	init();
	while (n--) {
	  insertAsLast(p->data);
	  p = p->succ;
	}
  }

  auto printL() {
	ListNodePosi<T> pl = header;
	for (int i = 0; i < _size; ++i) {
	  std::cout << pl->succ->data << " ";
	  pl = pl->succ;
	}
	std::cout << "\n";
  }

  ListNodePosi<T> getLast() { return trailer->pred; }

  ListNodePosi<T> getFirst() { return header->succ; }

  int deduplicate() {
	int oldSize = _size;
	Rank r = 1;
	auto p = first();
	while (trailer != (p = p->succ)) {
	  auto q = find(p->data, r, p);
	  q ? remove(q) : r++;
	}
	return oldSize - _size;
  }

  auto selectMax(ListNodePosi<T> p, int n) {//从p后的n个找最大.范围最大的元素的地址
	auto max = p;
	for (auto cur = p; 1 < n; n--)
	  if (((cur = cur->succ)->data) >= max->data)//lt less than, !lt not less than : >=
		max = cur;
	return max;
  }

  auto insertBefore(ListNodePosi<T> p, T e) {

  }

  void swapData(ListNodePosi<T> &a, ListNodePosi<T> &b) {
	ListNodePosi<T> tmp;
	tmp->data = a->data;
	a->data = b->data;
	b->data = tmp->data;
  }

  void selectionSort(ListNodePosi<T> p, int n) {//对p位置的后n的元素选排
	auto h = p->pred;
	auto tail = p;
	for (int i = 0; i < n; i++) {
	  tail = tail->succ;
	}
	while (1 < n) {
	  swapData(selectMax(), tail);
	  tail = tail->pred;
	  n--;
	}
  }
  void selectionSort() {
	selectionSort(*this, _size);
  }
};

#endif //DSA_IMPL_LIST_CPP
