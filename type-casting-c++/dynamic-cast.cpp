/*
Dynamic cast is primarily used for performing 
runtime type checking and casting within an 
inheritance hierarchy. It is used to safely 
downcast pointers or references from a base class 
to a derived class. If the cast is not valid, 
dynamic cast returns a null pointer (for pointers) 
or throws a std::bad_cast exception (for references).
*/

#include<iostream>
using namespace std;

class Base {
public:
    virtual void foo() {}
};
class Derived : public Base {};

int main(){

    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr != nullptr) {
        // The cast was successful
        derivedPtr->foo();
    } else {
        // The cast failed
        // Handle the failure condition
    }
    return 0;
}