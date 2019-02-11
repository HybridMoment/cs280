//
//  main.cpp
//  cs280
//
//  Created by Eric Rogers on 1/24/19.
//  Copyright © 2019 Eric Rogers. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool REVERSE_MODE = false;
bool UPPER_MODE = false;
bool NO_VOWEL_MODE = false;

// Function to reverse a string
void reverseStr(string& str){
    int n = str.length();
    // Swap characters
    for (int i = 0; i < n / 2; i++){
        
        swap(str[i], str[n - i - 1]);
        
    }
}
void upperStr(string& str){
    string capsStr = "";
    char ch;
    for(int i = 0; i < str.length(); i++){
        ch = str[i];
        ch = toupper(ch);
        capsStr = capsStr + ch;
    }
    str = capsStr;
}
void skipVowel(string& str){
    string str_no_vowels ="";
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
           str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            continue;
        }else{
            str_no_vowels = str_no_vowels + str[i];
        }
    }
    str = str_no_vowels;
}

int main(int argc, char* argv[]){
    
    //edge case: No args to process
    if(argc <= 1){
        cout<< "";
        return 0;
    }
    
    string arg_input = "";
    
    for(int i = 1; i < argc; i++){
        
        arg_input = argv[i];
        
        // check if modes need to be toggled
        if(arg_input.length() % 2 == 0){
            
            if(REVERSE_MODE){
                REVERSE_MODE = false;
            }else{
                REVERSE_MODE = true;
            }
        }
        if(arg_input.length() % 3 == 0){
            
            if(UPPER_MODE){
                UPPER_MODE = false;
            }else{
                UPPER_MODE = true;
            }
            
        }
        if(arg_input.length() % 5 == 0){
            
            if(NO_VOWEL_MODE){
                NO_VOWEL_MODE = false;
            }else{
                NO_VOWEL_MODE = true;
                
            }
        }
        //perform string transformations
        if(REVERSE_MODE){
            reverseStr(arg_input);
        }
        if(UPPER_MODE){
            upperStr(arg_input);
        }
        if(NO_VOWEL_MODE){
            skipVowel(arg_input);
        }
        
        cout<<arg_input;
        cout<<"\n";
       
        
    }
    return 0;
    
    
}
