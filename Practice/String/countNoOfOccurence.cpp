/*
string - "mississipi"
input - "issi"
count = 2
(overlapping as seperate occurence)
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s = "missississipi";
    string t = "issi";

    int count = 0;

    while(s.find(t) != -1){
        count++;
        s[s.find(t)] = '$';
    }
    cout << count << endl;

    return 0;
}