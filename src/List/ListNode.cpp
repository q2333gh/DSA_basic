//
// Created by 白桃乌龙 on 2022/8/23.
//

#ifndef DSA_IMPL_LISTNODE_CPP
#define DSA_IMPL_LISTNODE_CPP

using Rank = int;
template<typename T>
struct ListNode;
template<typename T> using ListNodePosi = ListNode<T> *;

template<typename T>
struct ListNode {
  T data;
  ListNodePosi<T> pred;
  ListNodePosi<T> succ;

  ListNode() = default;

  explicit ListNode(T e, ListNodePosi<T> p = nullptr, ListNodePosi<T> s = nullptr)
	  : data(e), pred(p), succ(s) {}//in java: this.e=e
  ListNodePosi<T> insertAsPred(T const &e) {//修改了四个指针的位置,分别是new的p和s以及this的p和this.p.s
	auto x = new ListNode(e, pred, this);
	pred->succ = x;
	pred = x;
	return x;
  }

  ListNodePosi<T> insertAsSucc(T const &e) {
	auto x = new ListNode(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
  }
};

#endif //DSA_IMPL_LISTNODE_CPP
