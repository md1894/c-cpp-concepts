#include<iostream>
#include<vector>
#include<algorithm>

void print_square(int x){
    std::cout << x*x << " ";
}

int main(){
    std::vector<int> list{1, 2, 3, 5, 9};
    std::for_each(list.begin(), list.end(), print_square);
    std::cout << std::endl;
    return 0;
}