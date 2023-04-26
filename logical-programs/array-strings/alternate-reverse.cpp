#include<iostream>
#include<string.h>
using namespace std;

void reverse_word(char *name, int len){
    for(int i = 0; i < len/2; i++){
        std::swap(name[i], name[len-i-1]);
    }
}

void print_alternate_reverse(char *para){
    bool reverse = false;
    char word[100];
    int j = 0;
    for(int i = 0; 1; i++){
        if(para [i] == ' ' || para[i] == '\0'){
            word[j] = '\0';
            j = 0;
            if(reverse == true){
                reverse_word(word, strlen(word));
                cout << word << " ";
                reverse = false;
            }else{
                cout << word << " ";
                reverse = true;
            }
            if(para[i] == '\0')
                break;
        }else{
            word[j] = para[i];
            j++;
        }
    }
}

int main(){
    char para[] = "mehul is my name and iye am very happy";
    print_alternate_reverse(para);
    cout << endl;
    return 0;
}

/*
mehul si my eman and eyi am yrev happy
*/