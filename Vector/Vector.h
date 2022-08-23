//
// Created by 白桃乌龙 on 2022/8/22.233342
//
#include <iostream>

#ifndef DSA_IMPL_VECTOR_H
#define DSA_IMPL_VECTOR_H

using Rank = int;
#define DEFAULT_CAPACITY 8

template<typename T>
struct Increase {
    virtual void operator()(T &e) { e++; }
};

template<typename T>
class Vector {
protected:
    Rank _size;
    int _capacity;
    T *_elem;

public:

    explicit //c,capacity ; s,size ; v,elem
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }

    Rank size() { return _size; }


    void expand() {
        if (_size < _capacity) return;
        if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
        T *oldElem = _elem;
        _elem = new T[_capacity <<= 1];
        for (int i = 0; i < _size; i++) _elem[i] = oldElem[i];
        std::cout << "expand to : " << _size << " ";
        delete[] oldElem;
    }

    Rank insert(Rank r, T const &e) {
        expand();
        for (int i = _size; i > r; i--) {
            _elem[i] = _elem[i - 1];
        }
        _elem[r] = e;
        _size++;
        return r;
    }

    int remove(Rank lo, Rank hi) {
        if (lo == hi) return 0;
        while (hi < _size)_elem[lo++] = _elem[hi++];
        _size = lo;
        return hi - lo;
    }

    T remove(Rank r) {//单元素删除重载
        T e = _elem[r];
        remove(r, r + 1);
        return e;
    }

    void traverse(void (*visit)(T &)) {//*函数指针
        for (int i = 0; i < _size; i++) {
            visit(_elem[i]);
        }
    }

    void increase(Vector<T> &V) {
        V.traverse(Increase<T>());
    }


    T &operator[](Rank r) { return _elem[r]; }

    void printV() {
        for (int i = 0; i < _size; ++i) {
            std::cout << _elem[i] << " ";
        }
        std::cout << std::endl;
    }

    Rank find(T const &e, Rank lo, Rank hi) {
        while (lo < hi) {
            if (e == _elem[hi]) return hi;
            else
                hi--;
        }
        return -1;
    }

    int disordered() const {
        int n = 0;
        for (int i = 1; i < _size; i++) {
            if (_elem[i - 1] > _elem[i]) {
                n++;
            }
        }
        return n;
    }

    void bubbleSort(Rank lo, Rank hi) {
        for (Rank last = --hi; lo < hi; hi = last)
            for (Rank i = last = lo; i < hi; i++) {
                swap(_elem[last = i], _elem[i + 1]);
            }
    }

    Rank maxItem(Rank lo, Rank hi) {
        Rank mx = hi;
        while (lo < hi--) {
            if (_elem[hi] > _elem[mx])
                mx = hi;
        }
        return mx;
    }

    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    void selecionSort(Rank lo, Rank hi) {
        while (lo < hi--) {
            swap(_elem[maxItem(lo, hi)], _elem[hi]);
        }
    }

//    int deduplicate(){
//        int oldSize=_size;
//        Rank i =
//    }
};

#endif //DSA_IMPL_VECTOR_H
