#include<iostream>
using namespace std;

int main(){
    const int var = 10;
    const int *ptr = &var;
    int *ptr1 = const_cast<int*> (ptr);
    *ptr1 = 15;
    cout << var << endl;// 10
    cout << *ptr1 << endl;// 15
    return 0;
}

/*
this is because of the compiler optimization
compiler replaces the value var with 10
*/

/*
10
15
*/