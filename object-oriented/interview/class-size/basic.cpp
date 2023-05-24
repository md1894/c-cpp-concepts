/*
In C++, the size of a class is determined by the size of its non-static data members. 
Static data members do not contribute to the size of an individual object 
of the class because they are not associated with any specific object instance.

The static data members are stored separately and shared among all the objects of the class. 
They exist independently of any specific object, 
and their memory is allocated once for the entire class. 
Therefore, the size of a class with static data members 
is not affected by the presence of those static members.

In your example, the `test` class has a static data member `i`, 
but since it is a static member, 
it does not contribute to the size of individual `test` objects. 
Therefore, the size of the `test` class is determined solely 
by its non-static members, which in this case is empty. 
As a result, the size of the `test` class is 1 byte (the size of an empty class).

It's important to note that the size of an empty class is not zero in C++. 
An empty class always has a non-zero size of at least 1 byte to ensure 
that objects of that class have a distinct address in memory.
*/

#include<iostream>
using namespace std;

class test {
    static int i;
};

int test::i = 5;

class emptyclass {

};

int main(){
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(test)= " << sizeof(test) << endl;
    cout << "sizeof(emptyclass)= " << sizeof(emptyclass) << endl;
    return 0; 
}

/*
output -->

sizeof(int) = 4
sizeof(test)= 1
sizeof(emptyclass)= 1

*/

/*
we can conclude that if a class has any static members
its size is not counted in class size
*/
