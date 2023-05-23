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