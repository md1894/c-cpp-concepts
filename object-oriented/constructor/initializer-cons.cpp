#include<iostream>
using namespace std;

class test {
    public:
    int a = 10;
    int b {12};
    int* ptr {};
    int* ptr1 = new int(55);
    int array [10] = {1, 55, 58, 12};
    //auto i = 15000;
    //error: non-static data member declared with placeholder ‘auto’ auto i = 15000;
};

int main() {
    test t;
    cout << t.a << endl;
    cout << t.b << endl;
    cout << t.ptr << endl;
    cout << *t.ptr1 << endl;
    cout << "printing array " << endl;
    for(auto i : t.array) {
        cout << i << endl;
    }
    return 0;
}

/*
10
12
0
55
printing array 
1
55
58
12
0
0
0
0
0
0
*/