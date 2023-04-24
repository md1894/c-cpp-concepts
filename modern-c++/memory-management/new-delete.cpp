/*
In C++, the `new` keyword is used to dynamically allocate memory at runtime, 
and unlike C's `malloc()`, it also initializes the memory block with default values.

When you use the `new` keyword to allocate memory for an object or an array of objects, 
the memory is initialized with the default value(s) for the type being allocated. 
For example, if you allocate memory for an `int` using `new`, the allocated memory block will be 
initialized to `0`.

Here's an example:

```c++
int *p = new int; // allocate memory for an int
// The memory block pointed to by p is initialized to 0

int *arr = new int[5]; // allocate memory for an array of 5 ints
// The memory block pointed to by arr is initialized to {0, 0, 0, 0, 0}
```

Note that the default value for a type depends on the type itself. 
For example, the default value for an `int` is `0`, but the default value for a `bool` is `false`.

It's worth noting that in C++11, you can also use brace-initialization syntax to 
initialize the allocated memory explicitly. For example:

```c++
int *p = new int{}; // allocate memory for an int and initialize to 0
int *arr = new int[5]{}; // allocate memory for an array of 5 ints and initialize to {0, 0, 0, 0, 0}
``` 

This syntax is useful when you want to initialize the allocated memory to a specific value, 
rather than relying on the default value for the type.
*/

#include<iostream>
using namespace std;

int main(){
    int *a = new int;
    cout << "Value of a is " << *a << endl;
    delete a;
    return 0;
}