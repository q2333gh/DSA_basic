//
// Created by 白桃乌龙 on 2022/8/22.23334

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
    T &operator[](Rank r) { return _elem[r]; }

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

    auto disordered() const {
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
        if (a == b) {
            return;
        }
        T tmp = a;
        a = b;
        b = tmp;
    }

    void selectionSort(Rank lo, Rank hi) {
        while (lo < hi--) {
            swap(_elem[maxItem(lo, hi)], _elem[hi]);
        }
    }

    void merge(Rank lo, Rank mi, Rank hi) {
        Rank i = 0;
        T *A = _elem + lo;
        Rank j = 0, lb = mi - lo;
        T *B = new T[lb]; //前子向量B[0, lb) <-- _elem[lo, mi)
        for (Rank i = 0; i < lb; i++) B[i] = A[i]; //复制自A的前缀
        Rank k = 0, lc = hi - mi;
        T *C = _elem + mi; //后子向量C[0, lc) = _elem[mi, hi)，就地
        while ((j < lb) && (k < lc)) //反复地比较B、C的首元素
            A[i++] = (B[j] <= C[k]) ? B[j++] : C[k++]; //将更小者归入A中
        while (j < lb) //若C先耗尽，则
            A[i++] = B[j++]; //将B残余的后缀归入A中——若B先耗尽呢？
        delete[] B; //释放临时空间：mergeSort()过程中，如何避免此类反复的new/delete？
    }

    void mergeSort(Rank lo, Rank hi) {//归并排序
        if (hi - lo < 2) return;
        int mi = (lo + hi) / 2;
        mergeSort(lo, mi);
        mergeSort(mi, hi);
        merge(lo, mi, hi);
    }

    Rank binSearch(T* S ,T const& e,Rank lo,Rank hi){
        while (lo<hi){
            Rank mi =(hi+lo)>>1;
            (e<S[mi])?hi=mi:lo=mi+1;
        }
        return lo-1;
    }
    Rank search(T const &e ,Rank lo,Rank hi){
        return binSearch(_elem,e,lo,hi);
    }


//    int deduplicate(){
//        int oldSize=_size;
//        Rank i =
//    }

};

#endif //DSA_IMPL_VECTOR_H
