#include <iostream>
#include "List/List.cpp"

int main(int argc, char *argv[]) {
    std::cout << "Hello, List!" << std::endl;
    List<int> l1{};
    for (int i = 0; i < 20; i++)
        l1.insertAsLast(rand() % 10);
    std::cout << "l1:\n";
    l1.printL();
    l1.deduplicate();
    std::cout << "dedu_l1:\n";
    l1.printL();
    List<int> l2;
    std::cout << "l2:\n";
    for (int i = 0; i < 5; i++)
        l2.insertAsLast(rand() % 10);
    l2.printL();
    List<int> l3;
    l3.copyNodes(l2.getFirst(), l2.size());
    std::cout << "l3 copyFrom l2 :\n";
    l3.printL();
    std::cout << "sel MAX: " << l3.selectMax(l3.getFirst(), l3.size())->data << "\n" << "l3 sort:\n";
    l3.selectionSort(l3.getFirst(), l3.size());
    l3.printL();
    return 0;
}
