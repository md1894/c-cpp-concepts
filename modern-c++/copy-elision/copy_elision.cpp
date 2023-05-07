/*
In this example, we have a class called `MyClass` that has a default constructor, 
copy constructor, and move constructor. We also have a function called `func` that returns an 
instance of `MyClass` by value.

When `func` is called, a local instance of `MyClass` is created on the stack inside the function. 
Then, `func` returns this instance by value, which should normally result in a copy constructor call 
to create a temporary object holding the return value, followed by a move constructor call to 
move the temporary object into `obj2` inside `main`.

However, with copy elision, the compiler can optimize away the copy and move constructor calls, 
and directly construct `obj2` inside `main` using the local instance of `MyClass` 
created inside `func`. This is possible because `obj2` is a non-const object 
and therefore can be modified directly.

When we run this program, the output is:

```
Default constructor called

```

As we can see, there is no output from the copy or move constructor, indicating that they 
were not called due to copy elision.

Note that the rules for copy elision are complex and can depend on many factors, 
including the optimization level used by the compiler. 
Therefore, the behavior of copy elision can be difficult to predict and should not be relied upon 
for program correctness.
*/

#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Default constructor called" << std::endl;
    }
    MyClass(const MyClass& other) {
        std::cout << "Copy constructor called" << std::endl;
    }
    MyClass(MyClass&& other) {
        std::cout << "Move constructor called" << std::endl;
    }
};

MyClass func() {
    MyClass obj;
    return obj;
}

int main() {
    MyClass obj2 = func();
    return 0;
}

/*
Default constructor called
*/

