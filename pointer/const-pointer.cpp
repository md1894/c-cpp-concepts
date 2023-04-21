#include<iostream>
using namespace std;

/*
Constant Pointer
A constant pointer is a pointer whose value cannot be changed after initialization.
The pointer itself is constant, but the value it points to can be changed.
The syntax for a constant pointer is:
*/
int main(){

    int x = 5;
    int y = 10;
    int* const ptr = &x;

    // The following line would be illegal, since ptr is a constant pointer:
    // ptr = &y;

    // The following line is legal, since the value of x can be changed:
    *ptr = 7;

    return 0;
}