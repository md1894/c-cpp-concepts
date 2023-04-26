/*
Smart pointers and weak pointers are both features in C++ that provide memory management capabilities. However, there are some key differences between them:

1. Ownership: Smart pointers have ownership of the memory they point to, 
meaning they are responsible for releasing the memory when it's no longer needed. 
Weak pointers, on the other hand, do not have ownership of the memory and rely on a corresponding 
shared pointer to ensure the memory is still valid.

2. Nullability: Smart pointers are guaranteed to always point to a valid object, 
while weak pointers may be null if the object they point to has been destroyed.

3. Functionality: Smart pointers provide full access to the object they point to, 
including the ability to modify its state. Weak pointers, on the other hand, 
provide only limited access to the object and cannot modify its state directly.

4. Lifetime management: Smart pointers use reference counting to manage the lifetime of the 
object they point to, while weak pointers do not affect the object's lifetime directly.

Here's an example that illustrates the differences between smart and weak pointers:

```c++
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(5);
    std::shared_ptr<int> sp2 = sp1; // reference count = 2
    std::weak_ptr<int> wp1 = sp1; // reference count not affected
    
    std::cout << "sp1 count: " << sp1.use_count() << std::endl; // prints 2
    std::cout << "wp1 count: " << wp1.use_count() << std::endl; // prints 2
    
    sp1.reset(); // reference count = 1
    std::cout << "sp2 count: " << sp2.use_count() << std::endl; // prints 1
    std::cout << "wp1 count: " << wp1.use_count() << std::endl; // prints 1
    
    sp2.reset(); // reference count = 0, memory deallocated
    std::cout << "wp1 expired: " << wp1.expired() << std::endl; // prints true
    
    std::shared_ptr<int> sp3 = wp1.lock(); // returns null pointer
    if (sp3 == nullptr) {
        std::cout << "wp1 lock failed" << std::endl;
    }
    
    return 0;
}
```

In this example, we create a shared pointer `sp1` and assign it to another shared pointer `sp2`, 
which increases the reference count to 2. We also create a weak pointer `wp1` that points to the 
same object as `sp1`, but does not affect the reference count.

We then reset `sp1`, which decreases the reference count to 1, and then reset `sp2`, 
which deallocates the memory. The weak pointer `wp1` is now expired since the object it points to 
no longer exists.

Finally, we attempt to lock the weak pointer `wp1` to create a new shared pointer `sp3`, 
but since the object no longer exists, the lock operation returns a null pointer.
*/

#include<iostream>
#include<memory>
using namespace std;

int main(){
    shared_ptr<int> sp1 = make_shared<int>(156);
    cout << sp1.use_count() << endl; // it gives the number that how many pointers pointing 
    // to the same memory location
    shared_ptr<int> sp2 = sp1;
    cout << sp2.use_count() << endl;

    std::weak_ptr<int> wp1 = sp1; // reference count not affected
    std::cout << "sp1 count: " << sp1.use_count() << std::endl; // prints 2
    std::cout << "wp1 count: " << wp1.use_count() << std::endl; // prints 2
    sp1.reset(); // reference count = 1
    std::cout << "sp2 count: " << sp2.use_count() << std::endl; // prints 1
    std::cout << "wp1 count: " << wp1.use_count() << std::endl; // prints 1
    
    sp2.reset(); // reference count = 0, memory deallocated
    std::cout << "wp1 expired: " << wp1.expired() << std::endl; // prints true
    
    std::shared_ptr<int> sp3 = wp1.lock(); // returns null pointer
    if (sp3 == nullptr) {
        std::cout << "wp1 lock failed" << std::endl;
    }
    return 0;
}