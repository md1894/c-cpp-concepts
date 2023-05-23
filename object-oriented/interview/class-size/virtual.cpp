#include<iostream>
using namespace std;

class test {
    public:
        virtual void fun(){}
};

int main(){
    cout << "sizeof(test) = " << sizeof(test) << endl;
    return 0;
}

/*
sizeof(test) = 8
*/

/*
to understand this output visit 
ptr-size.cpp in the same directory
*/