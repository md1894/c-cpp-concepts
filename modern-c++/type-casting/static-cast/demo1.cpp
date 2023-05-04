// C++ Program to demonstrate
// static_cast char* to int*
#include <iostream>
using namespace std;

/*
static cast will throw error in case of 
invalid explicit cast
*/

// Driver code
int main()
{
    int a = 10;
    char c = 'a';

    // Pass at compile time,
    // may fail at run time
    int* q = (int*)&c;

    int* p = static_cast<int*>(&c); //error: invalid ‘static_cast’ from type ‘char*’ to type ‘int*’
    return 0;
}
