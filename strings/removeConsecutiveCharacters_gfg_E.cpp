#include<iostream>
using namespace std;

string removeConsecutiveCharacter(string& s) {
        // code here.
        string ans = "";
        ans += s[0];
        for(int i=1; i<s.length(); i++){
            if(s[i] != s[i-1]){
                ans += s[i];
            }
        }
        return ans;
    }

    int main(){
        string s = "aabaabb";
        cout << removeConsecutiveCharacter(s) << endl;

        return 0;
    }