/*
The `std::unique_ptr` class provides several methods 
for managing and manipulating the unique pointer. 
Here are some of the key methods:

1. `get()`: Returns a pointer to the managed object or 
`nullptr` if the `unique_ptr` is empty.
   
2. `operator->()`: Allows access to the members of the managed 
object using the arrow operator.
   
3. `operator*()`: Returns a reference to the managed object.
   
4. `reset()`: Releases the ownership of the managed object 
and resets the `unique_ptr` to `nullptr`.
   
5. `release()`: Releases the ownership of the managed object 
and returns the raw pointer to the caller without 
destroying the object. 
The `unique_ptr` becomes empty.
   
6. `swap()`: Swaps the managed objects between 
two `unique_ptr` instances.
   
7. `operator bool()`: Checks whether the `unique_ptr` 
holds a valid object (not null).

These are some of the most commonly used methods of `std::unique_ptr`. 
There are additional methods and overloads available in the C++ standard library, 
such as custom deleters and specialized constructors, 
that provide more advanced functionality. 
You can refer to the C++ documentation for a comprehensive list of 
methods and their descriptions: 

https://en.cppreference.com/w/cpp/memory/unique_ptr
*/


#include<iostream>
#include<memory>
using namespace std;

class myClass {
    public:
        myClass(){
            cout << "Creating object of myClass " << endl;
        }

        ~myClass() {
            cout << "Destroying object of myClass " << endl;
        }

        void action() {
            cout << "Inside myClass::action() method " << endl;
        }
};

int main() {

    unique_ptr<myClass> uptr (new myClass());
    
    //know the address of our memory
    cout << "Address to which uptr is pointing is " << uptr.get() << endl;
    uptr->action();
    
    // transferring ownership to another unique_ptr

    unique_ptr<myClass> uptr1 = std::move(uptr);
    cout << "Address to which uptr1 is pointing is " << uptr1.get() << endl;
    uptr1->action();
    return 0;
}

/*
Creating object of myClass 
Address to which uptr is pointing is 0x558efa202eb0
Inside myClass::action() method 
Address to which uptr1 is pointing is 0x558efa202eb0
Inside myClass::action() method 
Destroying object of myClass
*/