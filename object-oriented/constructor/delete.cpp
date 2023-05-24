#include<iostream>
using namespace std;

int main(){
    int *a = new int(10);
    delete a;
    //a = nullptr; // if this line is uncommented 
    // this error is removed
    delete a;
    return 0;
}

/*
output:

runtime error

free(): double free detected in tcache 2
Aborted (core dumped)

*/