#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector/Vector.cpp"
#include "googletest/googletest/include/gtest/gtest.h"

#include "List/ListNode.cpp"
#include "List/List.cpp"

int size = 100000;


TEST(TestCase, test1) {
    ASSERT_EQ(5, 5);
}

TEST(TestCase, test2) {
    Vector<int> v2(0, 0, 0);
    for (int i = 0; i < size; ++i) {
        v2.insert(0, rand() & size);
    }
    v2.selectionSort(0, v2.size());
}

TEST(TestCase, test3) {
    std::cout << "Hello, Vector!" << std::endl;
    Vector<int> v1(0, 0, 0);
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        v1.insert(0, rand() % 10);
    }
    std::cout << std::endl;
    std::cout << "size:" << v1.size();
    std::cout << std::endl;
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << "\t";
    }
    std::cout << std::endl;
    v1.remove(0, 3);
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "remove pos 1 : " << v1.remove(0) << std::endl;
    std::cout << "remove pos 2 : " << v1.remove(0) << std::endl << "new v1: ";
    v1.printV();
    std::cout << "try find 0,pos(max rank) : " << v1.find(0, 0, 4) << "  get via pos: " << v1[v1.find(0, 0, 4)]
              << std::endl;
//    v1.increase(v1);
//    std::cout<<"+1 v1:";v1.printV();
    std::cout << "disoredred n: " << v1.disordered() << "\n";
//    v1.bubbleSort(0,v1.size());
//    std::cout<<"bubbleSort n1: ";
    v1.selectionSort(0, v1.size());
    v1.printV();
    int a = 10;
    int b = 20;
    v1.swap(a, b);
    std::cout << a << " " << b << "\n" << "swap: \n";
    v1.swap(v1[0], v1[1]);
    v1.printV();
    for (int i = 0; i < 5; i++) {
        v1.insert(0, rand() % 10);
    }
    v1.mergeSort(0, v1.size());
    v1.printV();
    std::cout << "try search value :5 at pos :" << v1.search(5, 0, v1.size());

}

TEST(TestCase, test4) {
    Vector<int> v2(0, 0, 0);
    for (int i = 0; i < size; ++i) {
        v2.insert(0, rand() & size);
    }
    v2.selectionSort(0, v2.size());
    std::cout << v2.find(5000, 0, v2.size());
}

TEST(TestCase, test5) {
    List<int> l1(2);
    for (int i = 0; i < 20; ++i) {
        l1.insertAsLast(rand() % 10);
    }
    l1.printL();
    std::cout << l1.find(5, l1.size(), l1.getLast()) << " ";
    std::cout << l1.find(3, l1.size(), l1.getLast()) << " ";

}

TEST(TestCase, test6) {
    List<int> l2(2);
    for (int i = 0; i < 20; ++i) {
        l2.insertAsLast(i + 1);
    }
    l2.printL();
    std::cout << l2.find(5, l2.size(), l2.getLast()) << " ";
    std::cout << l2.find(3, l2.getFirst(), l2.size()) << " ";

}

int main(int argc, char *argv[]) {
    srand((unsigned) time(nullptr));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
