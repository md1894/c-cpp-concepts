#include<iostream>
using namespace std;

template<typename T>
T myMax(T a, T b){
    return a >= b ? a : b;
}

int main(){
    cout << myMax(3.0, 5.99) << endl;
    cout << myMax(789, 564) << endl;
    cout << myMax('t', 'm') << endl;
    return 0;
}

/*
5.99
789
t
*/