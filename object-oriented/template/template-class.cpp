#include<iostream>
using namespace std;

template<typename T>
class Array{
    int size;
    T *ptr;

    public:
        Array(int);
        ~Array();
        void print();
        void set_values(T a[], int n);


};

template<typename T> Array<T>::Array(int size){
    this->ptr = new T[size];
    this->size = size;
}

template<typename T> void Array<T>::print(){
    for(int i = 0; i < size; i++){
        cout << this->ptr[i] << endl;
    }
}

template<typename T> void Array<T>::set_values(T a[], int n){
    if(n != size){
        cout << "Invalid Size " << endl;
        return;
    }
    for(int i = 0; i < size; i++){
        this->ptr [i] = a[i];
    }
}

template<typename T> Array<T>::~Array(){
    delete[] this->ptr;
}

int main(){
    Array<int> a(5);
    int a1[]{1, 2, 3, 4, 5};
    a.set_values(a1, 5);
    a.print();
    return 0;
}