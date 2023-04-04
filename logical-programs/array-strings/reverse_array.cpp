#include<iostream>
using namespace std;

void reverse_array(int a[], int n){
    for(int i = 0; i < n/2; i++){
        /// first element gets swaped with the last element
        /// increment pointer from front and decrement pointer from end
        std::swap(a[i], a[n-i-1]);
    }
}

int main(){
    int a[5] = {1,2,3,4,5};
    int an = 5;
    int b[6] = {1,2,3,4,5,6};
    int bn = 6;

    reverse_array(a, 5);
    reverse_array(b, 6);

    cout << "Reversed Array a is " << endl;

    for(int i=0; i < 5; i++){
        cout << a[i] << endl;
    }

    cout << "Reversed Array b is " << endl;

    for(int i=0; i < 6; i++){
        cout << b[i] << endl;
    }

    return 0;
}