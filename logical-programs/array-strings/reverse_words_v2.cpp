/*
 * c++ program to reverse words in a string and making its first letter
 * as upper case
 * */


#include <iostream>
#include <cstring>

void reverseWord(char* word, int start, int end) {
    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* input) {
    int length = strlen(input);
    int wordStart = 0;
    int wordEnd = 0;
    bool isWord = false;
    
    for (int i = 0; i <= length; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            if (isWord) {
                reverseWord(input, wordStart, wordEnd - 1);
                isWord = false;
            }
        } else {
            if (!isWord) {
                wordStart = i;
                isWord = true;
            }
            wordEnd = i + 1;
        }
    }
    
    // Capitalize the first letter of each word
    for (int i = 0; i < length; i++) {
        if (i == 0 || (i > 0 && input[i - 1] == ' ')) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                input[i] -= 32;
            }
        } else {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                input[i] += 32;
            }
        }
    }
    
    return input;
}

int main() {
    char sentence[100];
    std::cout << "Enter a sentence: ";
    std::cin.getline(sentence, 100);
    
    char* modifiedSentence = reverseWords(sentence);
    std::cout << "Modified sentence: " << modifiedSentence << std::endl;
    
    return 0;
}

