#include<iostream>
#include<typeinfo>
using namespace std;

/*
typeid.cpp:25:24: 
error: cannot ‘dynamic_cast’ ‘baseptr’ (of type ‘class Base*’) to type ‘class Derived*’ (source type is not polymorphic)
Derived* obj = dynamic_cast<Derived*> (baseptr);

*/

class Base {
    public:
    // it is compulsory to make any one method virtual
    // to make relation as polymorphic, otherwise
    // it will give compilation error, refer above
    virtual ~Base(){

    }
};

class Derived : public Base {
    public:
        void derived_class_method() {
            cout << "Inside derived_class_method()\n";
        }
};


/*
It's important to note that dynamic_cast is used with polymorphic types 
(classes with at least one virtual function) 
and it performs a runtime type check. 
If the cast is successful, the downcasted pointer 
will be non-null, and if it fails 
(e.g., when the object is not of the expected type), 
it will return a null pointer.

RTTI provides a mechanism for type identification 
and allows you to make decisions based on the 
actual type of objects at runtime. 
However, it should be used judiciously as excessive 
use of RTTI may indicate a design flaw and 
can impact performance.
*/

int main() {
    Base* baseptr = new Derived();

    if(typeid(*baseptr) == typeid(Derived)) {
        
        cout << "pointer is holding the derived class object address" << endl;
        Derived* obj = dynamic_cast<Derived*> (baseptr);
        
        if(obj != nullptr) {
            obj->derived_class_method();
        
        }
    }else{
        cout << "type is not of Derived " << endl;
    }
    return 0;
}

/*
pointer is holding the derived class object address
Inside derived_class_method()
*/