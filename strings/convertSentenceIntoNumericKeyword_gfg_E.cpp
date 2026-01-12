#include<iostream>
#include<string>
using namespace std;

string printSequence(string S) {
    // code here.
    string ans = "";
    string keyword[] = {"2", "22", "222","3", "33", "333","4", "44", "444","5", "55", "555","6", "66", "666","7", "77", "777","7777", "8", "88","888", "9", "99", "999", "9999"};

    for(int i=0; i<S.length(); i++){
        if(S[i] == ' '){
            ans += "0";
        }
        else{
            int j = S[i]-'A';
            ans += keyword[j];
        }
    }
    return ans;   
}

int main(){
    string s = " VHTCH HJ";
    cout << printSequence(s) << endl;

    return 0;
}