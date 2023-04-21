#include<iostream>
using namespace std;
/*
A constant pointer to const is a pointer whose value cannot be changed, 
and the object it points to cannot be modified. 
The syntax for a constant pointer to const is:
*/

int main(){
    const int x = 5;
    const int y = 10;
    const int* const ptr = &x;

    // The following line would be illegal, since ptr is a constant pointer:
    // ptr = &y;

    // The following line would be illegal, since the object ptr points to is const:
    // *ptr = 7;

    return 0;
}