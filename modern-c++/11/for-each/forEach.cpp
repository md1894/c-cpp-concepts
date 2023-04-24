#include <iostream>
using namespace std;


int main() {
	
	int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
    cout << endl;
	for (const auto & x : arr) {
		
		cout << x << " ";
	}
    cout << endl;
	for (auto x : { 1,2,3,4 }) {
		cout << x << " ";
	}
    cout << endl;
	return 0;
}