#include<iostream>
using namespace std;


// sizeof int is 4 bytes
class test {
    int i;
};

int main(){
    cout << "size of class test is = " << sizeof(test) << endl;
    return 0;
}

/*
size of class test is = 4
*/