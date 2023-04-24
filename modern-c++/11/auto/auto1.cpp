#include<iostream>
using namespace std;

int main(){
    /// use of initializer list with normal variable declaration
    int a[5]{1, 2, 3, 4, 5};

    /// if used with auto type , it will give compilation error
    //auto a1[5]{1, 3, 5, 5, 7};
    /*
    error: ‘a1’ declared as array of ‘auto’
    9 |     auto a1[5]{1, 3, 5, 5, 7};
    */
    //auto a3{1, 3, 5, 5, 7}
    /*
    error: direct-list-initialization of ‘auto’ requires exactly one element [-fpermissive]
    9 |     auto a1{1, 3, 5, 5, 7};
    */

    /*
    to solve above problem , we have to use initializer list like this
    */
    auto a2 = {1, 2, 3, 4, 5};
    return 0;
}