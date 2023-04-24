#include<iostream>
using namespace std;

int main(){
    auto list = {1, 5, 7, 9, 5};
    auto begin = std::begin(list);
    auto end = std::end(list);
    for(; begin != end; begin++){
        auto v = *begin;
        cout << v << " ";
    }
    cout << endl;
    return 0;
}