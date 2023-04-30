#include<iostream>
using namespace std;

void print_pair_sum(int *array, int sum, int n){
    int target;
    for(int i = 0; i < n - 1; i++){
        target = sum - array[i];
        for(int j = i + 1; j < n; j++){
            if(array[j] == target){
                cout << array[i] << " " << array[j] << endl;
            }
        }
    }
}

int main(){
    int array[]{10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1};
    int sum = 11;
    int n = 13;
    print_pair_sum(array, sum, n);
    return 0;
}