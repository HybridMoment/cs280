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
#include <map>
#include <iterator>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){
    
    if(argc <=2){
        cout<< "TWO FILENAMES REQUIRED";
        return 0;
    }
    
    ifstream subs_file;
    ifstream words_file;
    string subs_file_name = argv[1];
    string words_file_name = argv[2];
    
    subs_file.open(subs_file_name);
    words_file.open(words_file_name);
    
    //Edge case, bad files
    if(!subs_file.is_open()){
        cout<< "BAD FILE "<< subs_file_name << "\n";
        return 0;
    }
    if(!words_file.is_open()){
        cout<< "BAD FILE "<< words_file_name << "\n";
    }
    //Edge case, subs file is empty
    string line;
    if(subs_file.eof()){
        if(words_file.eof()){
            cout<<"";
            return 0;
        }else{
            //No subs just print out each line of word file
            while(getline(words_file, line)){
                cout<< line <<"\n";
            }
        }
        subs_file.close();
        words_file.close();
        return 0;
    }
    // now we can process the sub file knowing its not empty
    queue<string> sub_word_queue;
    string token;
    map<string, string> sub_word_map;
    string key;
    string value;
    //parse sub file line by line
    while(getline(subs_file, line)){
        stringstream ss (line);
        while(ss>>token){
            sub_word_queue.push(token);
        }
        if(sub_word_queue.size()!= 2){
            //empty queue and skip line since its not formatted correctly
            while(!sub_word_queue.empty()){
                sub_word_queue.pop();
            }
        }else{
            //proper format need to store values into map
            key = sub_word_queue.front();
            sub_word_queue.pop();
            value = sub_word_queue.front();
            sub_word_queue.pop();
            //after getting the key/value we need to store it in the map
            sub_word_map[key] = value;
        }
    }
    // parse word file line by line
    map<string,string>::iterator it;
    while(getline(words_file, line)){
        stringstream ss (line);
        while(ss>>token){
            //check if token needs to be changed
            it = sub_word_map.find(token);
            if(it != sub_word_map.end()){
                //word needs to be changed
                token = sub_word_map[token];
            }
            cout<<token<<" ";
            
        }
        cout<<"\n";
    }
    return 0;
    
    
    
}
