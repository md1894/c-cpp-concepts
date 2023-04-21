#include<iostream>
using namespace std;

/*
Pointer to const
A pointer to const is a pointer that can be changed to point to different objects, 
but the object it points to cannot be modified. The syntax for a pointer to const is:
*/

int main(){
    
    const int x = 5;
    const int y = 10;
    const int* ptr = &x;

    // The following line is legal, since ptr can be changed to point to y:
    ptr = &y;

    // The following line would be illegal, since the object ptr points to is const:
    // *ptr = 7;

    return 0;
}