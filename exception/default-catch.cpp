#include<iostream>
using namespace std;

int main(){
    int a = -1;
    try{
        if(a < 0){
            throw 25;
            cout << "After Throw " << endl;
        }
    }catch(char a){ /// 25 is thrown but it is not converted to char type (implicit conversion)
        cout << "Caught execption a " << endl;
    }catch(...){/// default catch block
        cout << "Caught as a default exception " << endl;
    }
    return 0;
}

/*
exception thrown , does not support implicit type conversion
*/

/*
output:

Caught as a default exception
*/
