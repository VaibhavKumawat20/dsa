#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str = "a quick brown fox jumps over the lazy dog";

    stringstream ss(str);
    vector<string> vec;
    string word;

    // while(ss >> word){ // for printing words
    //     vec.push_back(word);
    // }
    // for(string s : vec){
    //     cout << s << endl;
    // }

    // printing no. of characters in each word
    vector<int> ch;
    while(ss >> word){
        ch.push_back(word.length());
    }
    for(int i : ch){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}