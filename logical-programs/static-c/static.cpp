#include<iostream>
using namespace std;

void fun(int a) {
    static int i = 0;
    if(a%2 == 0)
        cout << ++i << endl;
    else
        cout << i << endl;
}

int main() {
    fun(4);
    fun(15);
    fun(2);
    fun(6);
    return 0;
}

/*
1
1
2
3
*/