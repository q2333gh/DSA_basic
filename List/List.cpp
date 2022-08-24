//
// Created by 白桃乌龙 on 2022/8/23.
//

#ifndef DSA_IMPL_LIST_CPP
#define DSA_IMPL_LIST_CPP

#include "ListNode.cpp"

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
    }

public:
    T &operator[](Rank r) const {
        ListNode<T> p = first();
        while (0 < r--)p = p.succ;
        return p.data;
    }

    explicit List(int n = 0) { init(); }

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

    auto printL() {
        ListNodePosi<T> pl = header;
        for (int i = 0; i < _size; ++i) {
            std::cout << pl->succ->data << " ";
            pl = pl->succ;
        }
        std::cout << "\n";
    }


    ListNodePosi<T> getLast() {
        return trailer->pred;
    }

    ListNodePosi<T> getFirst() {
        return header->succ;
    }


};


#endif //DSA_IMPL_LIST_CPP
