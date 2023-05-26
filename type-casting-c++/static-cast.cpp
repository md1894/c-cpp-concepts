/*
Static Cast:

Static cast is used for implicit conversions between related types. 
It can perform conversions such as arithmetic, pointer, 
and reference conversions, as well as explicit type conversions. 
The compiler checks the validity of the cast at compile-time
*/

#include<iostream>
using namespace std;

// Another example: 
// static_cast from base class to derived class
class Base {};
class Derived : public Base {};

int main(){
    int num1 = 10;
    // static_cast from int to double
    double num2 = static_cast<double>(num1);  

    Base* basePtr = new Derived();
    Derived* derivedPtr = static_cast<Derived*>(basePtr);

    return 0;
}