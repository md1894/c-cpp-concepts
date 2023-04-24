
/*
The `auto` keyword in C++11 is used to allow the compiler to automatically deduce 
the data type of a variable from its initializer expression. 
Here are some important facts about the `auto` keyword:

1. `auto` is a new keyword introduced in C++11 standard and it is a part of the type inference feature.
2. The `auto` keyword can be used in place of a type declaration in variable declaration statements. 
   For example, instead of writing `int i = 10;`, you can write `auto i = 10;` 
   to let the compiler deduce the data type of `i`.
3. The `auto` keyword can be used with any type of initializer expression, 
   including literals, variables, and expressions.
4. The `auto` keyword is particularly useful for declaring complex types 
   that are difficult or tedious to type out explicitly, such as iterators or template types.
5. Using `auto` does not mean that the variable has no type, 
   rather it means that the type is inferred by the compiler at compile-time 
   based on the initializer expression.
6. The `auto` keyword is not the same as the `decltype` keyword, 
   which is used to deduce the type of an expression. 
   While `auto` deduces the type of the initializer expression, `decltype` deduces 
   the type of the expression itself.
7. In C++14, the `auto` keyword was extended to allow for the deduced type to be specified 
   as a trailing return type. This is useful for functions that return complex types or for 
   lambdas that use complex return types.

Overall, the `auto` keyword is a powerful tool for simplifying code and reducing typing errors, 
especially when dealing with complex types. 
However, it should be used judiciously, as excessive use of `auto` can make code harder to read 
and understand.
*/

#include<iostream>
using namespace std;

double sum(double a, double b){
    return a+b;
}

int main(){
    auto i = 10;// integer
    auto j = 10 + 15.37; // final type of expression is float
    auto res = sum(25.78 , 78.23); // return type of a function
    static auto y = 2; // auto can have static qualifier

    /*
    variable x is an const variable , but when it is assigned to v (auto)
    it's type is deduced as 'int', in actual data type of x is --> 'const int'
    */
    const int x = 10;
    auto v = x;
    v = 150;

    cout << v << endl;

    /*
    to solve the above problem
    you must use const with auto , to make that variable const
    */
   
   const auto v1 = x;
   // v1 = 250; // this code will result in error
   /*
   error: assignment of read-only variable ‘v1’
            v1 = 250;
   */

  /* if we declare auto a reference type , no need to add const */
    auto &v2 = x;
    // type of v2 is const int& (const integer reference)
    //v2 = 250;
    /*
    error: assignment of read-only reference ‘v2’
        v2 = 250;
    */
    auto ptr = &x;
    //*ptr = 350;
    /*
    error: assignment of read-only location ‘* ptr’
        *ptr = 350;
    */
    return 0;
}










