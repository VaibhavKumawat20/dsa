/*
"what it is is a mess"
word - is
O/P - 2 times
*/
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    string str = "what it is is a complete mess";

    vector<string> vec;

    stringstream ss(str);
    string word;

    while(ss >> word){
        vec.push_back(word);
    }

    int count = 0;
    word = "is";

    for(string i : vec){
        if(i == word){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}