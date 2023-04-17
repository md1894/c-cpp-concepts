#include<iostream>
using namespace std;

int main(){
    int *a = new int(10);
    delete a;
    delete a;
    return 0;
}

/*
output:

runtime error

free(): double free detected in tcache 2
Aborted (core dumped)

*/