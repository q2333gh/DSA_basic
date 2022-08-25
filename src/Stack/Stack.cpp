#include "../Vector/Vector.cpp"
template<typename T>
class Stack :public Vector<T>{
public:
    Stack(){

    }
    ~Stack(){

    }

    auto empty(){
        bool e=_size;
        return e;
    }
    auto push(T const &e){
        insert(size(),e);
    }
    auto pop(){
        return remove(size()-1);
    }
    auto top(){
        return (*this)[size-1];
    }
};