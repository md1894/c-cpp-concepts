#include<iostream>
using namespace std;

int main() {
    string str = "Hello, World";

    // Extracting a substring starting from 
    // position 7 (inclusive) with a length of 5
    string substr = str.substr(7, 5);

    cout << "ORIGINAL STRING IS : " + str << endl;
    cout << "SUBSTRING IS       : " + substr << endl;
    return 0;
}

/*
ORIGINAL STRING IS : Hello, World
SUBSTRING IS       : World
*/