/*
In a 64-bit compiler and system, 
the size of a pointer is typically 8 bytes. 
This means that a pointer variable, 
regardless of the type it points to, 
will occupy 8 bytes of memory.

The 64-bit systems have a larger addressable memory range 
compared to 32-bit systems, allowing them to handle larger amounts of data. 
Therefore, the size of a pointer in a 64-bit system
 is doubled compared to a 32-bit system.

However, it's important to note that the actual size of a pointer can still vary 
depending on the specific platform and compiler. 
In some specialized environments or certain architectures, 
the size of a pointer may be different. 
Nonetheless, on most modern 64-bit systems, the standard size for a pointer is 8 bytes.
*/

#include<iostream>
using namespace std;

int main(){
    int *ptr = new int(10);
    void *vptr;
    cout << "size of int* ptr = " << sizeof(ptr) << endl;
    cout << "size of vptr = " << sizeof(vptr) << endl;
    return 0;
}

/*
size of int* ptr = 8
size of vptr = 8
*/