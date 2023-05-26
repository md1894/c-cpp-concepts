/*
Const cast is used to add or remove the const or volatile qualifiers 
from a variable. It is typically used to remove constness and 
enable modifications to a variable that was originally 
declared as const. However, modifying a variable that was 
initially declared const leads to undefined behavior.
*/

#include<iostream>
using namespace std;

int main() {
    const int num1 = 10;
    int* mutableNum = const_cast<int*>(&num1);
    
    // Undefined behavior: modifying a const variable
    *mutableNum = 20;  
    
    cout << "num1 = " << num1 << endl;
    cout << "*mutableNum = " << *mutableNum << endl;
    return 0;
}

/*
due to compiler code optimization
num1 is directly replaced by 10 , as it is const

num1 = 10
*mutableNum = 20
*/