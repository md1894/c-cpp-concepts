#include<iostream>
using namespace std;

int main(){
    try{
        try{
            throw 2;
        }
        catch(int a){
            cout << "Handling Partially " << endl;
            throw;// rethrow the exception
        }
    }catch(...){
        cout << "Handling remaining " << endl;// this block will handle the remaining part of exception
    }
    return 0;
}

/*
Handling Partially 
Handling remaining
*/