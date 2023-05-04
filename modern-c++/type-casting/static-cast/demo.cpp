#include<iostream>
using namespace std;

/*
This is the simplest type of cast that can be used. 
It is a compile-time cast. It does things like implicit conversions between types 
(such as int to float, or pointer to void*), and it can also call explicit conversion functions.
*/

int main(){
    float f = 3.5;
    // Implicit type case
    // float to int
    int a = f;
    cout << "The Value of a: " << a;
    // using static_cast for float to int
    int b = static_cast<int>(f); // more readable code
    cout << "\nThe Value of b: " << b;
    return 0;
}