#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector/Vector.h"
int main() {
    srand((unsigned)time(nullptr));
    std::cout << "Hello, Vector!" << std::endl;
    Vector<int> v1(0,0,0);
    for (int i = 0; i < v1.size(); ++i) {
        std::cout<<v1[i]<<"\t";
    }
    std::cout<<std::endl;
    for (int i = 0; i < 10; i++) {
        v1.insert(0, rand()%10);
    }
    std::cout<<std::endl;
    std::cout<<"size:"<<v1.size();
    std::cout<<std::endl;
    for (int i = 0; i < v1.size(); ++i) {
        std::cout<<v1[i]<<"\t";
    }
    std::cout<<std::endl;
    v1.remove(0,3);
    for (int i = 0; i < v1.size(); ++i) {
        std::cout<<v1[i]<<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"remove pos 1 : " <<v1.remove(0)<<std::endl;
    std::cout<<"remove pos 2 : " <<v1.remove(0)<<std::endl<<"new v1: ";
    v1.printV();
    std::cout<<"try find 0,pos(max rank) : "<<v1.find(0,0,4)<<"  get via pos: "<<v1[v1.find(0,0,4)]<<std::endl;
//    v1.increase(v1);
//    std::cout<<"+1 v1:";v1.printV();
    std::cout<<"disoredred n: "<<v1.disordered();
//    v1.bubbleSort(0,v1.size());
//    std::cout<<"bubbleSort n1: ";
    v1.selecionSort(0,v1.size());
    v1.printV();
    int a=10;int b=20;
    std::swap(a,b);
    std::cout<<a<<" "<<b;

    return 0;
}
