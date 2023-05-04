#include<iostream>
#include<string.h>
using namespace std;

void reverse(char *word){
	int len = strlen(word);
	for(int i = 0; i < len/2; i++){
		std::swap(word[i], word[len-i-1]);
	}
}

int main(){
	char *sentence = "welcome to GDB online";
	int len = strlen(sentence);
	char word[100];
	int j = 0;
	for(int i = len-1; i >= 0; i--){
		if(sentence[i] != ' ' && i != 0){
			word[j] = sentence[i];
			j++;
		}else {
			if(i == 0){
				word[j] = sentence[i];
				word[j+1] = '\0';
			}else{
				word[j] = '\0';
			}
			reverse(word);
			cout << word;
			if(sentence[i] == ' ')
				cout << " ";
			j = 0;
		}
	}
	return 0;
}
