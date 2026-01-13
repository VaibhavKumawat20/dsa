#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void findAllDuplicates(string s){
    unordered_map<char, int> freq;

    //count frequency of each character
    for(char c : s){
        freq[c]++;
        // cout << freq[c] << ", ";
    }

    for(auto it : freq){
        if(it.second > 1){
            cout << "['" << it.first << "', " << it.second << "], ";
        }
    }
}

int main(){
    string s = "geeksforgeeks";
    findAllDuplicates(s);

    return 0;
}