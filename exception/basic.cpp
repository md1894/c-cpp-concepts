/*


Exception handling in C++ is a mechanism that allows you to handle errors or exceptional situations 
that may occur during program execution. The use of exception handling in a C++ project can 
provide several benefits, such as improving the robustness and reliability of the program, 
making the code more readable, and reducing the amount of error handling code that needs to be written.

Here are some ways you can use exception handling in a C++ project:

1. Detecting errors: Exception handling can be used to detect and handle errors that occur 
during program execution, such as division by zero, out-of-range array indexes, and file I/O errors.

2. Recovering from errors: In some cases, it may be possible to recover from an error and 
continue program execution. For example, if a file I/O error occurs, the program could prompt the user 
to enter a different file name or location.

3. Simplifying error handling: By using exception handling, you can simplify error handling code 
and reduce the amount of code needed to handle errors. This can make the code more readable and 
easier to maintain.

4. Implementing resource management: Exception handling can be used to implement resource management, 
such as releasing memory or closing files, in a safe and reliable manner.



It's important to note that exception handling can add overhead to the program and 
should be used judiciously. You should only use exception handling for exceptional situations 
that are not part of the normal program flow.
*/

#include<iostream>
using namespace std;

int main(){

    int x = -1;
    try{
        cout << "Inside Try Block " << endl;
        if(x < 0){ /// this is acting as a runtime error
            throw x;
            cout << "After Throw Never Executed " << endl;
        }
    }catch(int x){
        cout << "Inside Catch Block " << endl;
    }
    cout << "This Line is executed after catch " << endl;
    return 0;
}

/*
output : 

Inside Try Block 
Inside Catch Block 
This Line is executed after catch
*/