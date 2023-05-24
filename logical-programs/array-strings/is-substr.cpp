#include<iostream>
using namespace std;


bool isSubstr(string main_str, string substr){
    int mlen = main_str.length();
    int slen = substr.length();
    for(int i = 0; i < mlen; i++){
        int j;
        for(j = 0; j < slen; j++){
            if(main_str[i+j] != substr[j])
                break;
        }
        if(j == slen)
            return true;
    }
    return false;
}

int main(){
    string main_string = "My Name is Mehul";
    string substr = "Name";
    if(isSubstr(main_string, substr)){
        cout << "Substring " + substr << " is Present in " + main_string << endl;
    }else{
        cout << "Not Found" << endl;
    }
    return 0;
}