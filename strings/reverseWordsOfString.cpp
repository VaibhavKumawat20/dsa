#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    string str = "a quick brown fox jumps over the lazy dog";

    stringstream ss(str);
    vector<string> vec;
    string word;

    while(ss >> word){ // for printing words
        vec.push_back(word);
    }

    reverse(vec.begin(), vec.end());
    for(string s : vec){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}