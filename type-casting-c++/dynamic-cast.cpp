/*
Dynamic cast is primarily used for performing 
runtime type checking and casting within an 
inheritance hierarchy. It is used to safely 
downcast pointers or references from a base class 
to a derived class. If the cast is not valid, 
dynamic cast returns a null pointer (for pointers) 
or throws a std::bad_cast exception (for references).
*/

/*
In C++, the `dynamic_cast` operator is used for performing runtime type checking 
and type conversions between polymorphic types. 
It allows you to safely downcast a pointer or reference 
of a base class to a pointer or reference of a derived class.

The syntax of `dynamic_cast` is as follows:

```cpp
dynamic_cast<new_type>(expression)
```

Here, `new_type` is the target type 
to which you want to cast, and 
`expression` is the pointer or reference 
you want to cast. 
It's important to note that `dynamic_cast` can only be used 
with pointers or references to classes 
that have at least one virtual function.

The `dynamic_cast` operator performs the following:

1. If the cast is from a pointer type, 
it returns a null pointer if the cast fails and the object pointed to otherwise.

2. If the cast is from a reference type, 
it throws a `std::bad_cast` exception if the cast fails and the reference to the object otherwise.

Here's an example to illustrate the usage of `dynamic_cast`:

```cpp
#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void specificFunction() {
        std::cout << "Specific function of Derived class\n";
    }
};

int main() {
    Base* basePtr = new Derived;
    
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        // Cast successful
        derivedPtr->specificFunction();
    } else {
        // Cast failed
        std::cout << "Failed to cast Base* to Derived*\n";
    }
    
    delete basePtr;
    
    return 0;
}
```

In this example, `dynamic_cast` is used to downcast a pointer 
of the base class `Base` to a pointer of the derived class `Derived`. 
If the cast is successful, 
the `specificFunction()` of the `Derived` class is called. 
Otherwise, a failure message is displayed.

It's important to use `dynamic_cast` judiciously 
and only when necessary since it incurs some runtime 
overhead due to the type checking involved.
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
        cout << "Invalid Cast " << endl;
    }
    return 0;
}
