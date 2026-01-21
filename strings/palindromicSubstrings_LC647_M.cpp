#include<iostream>
using namespace std;

int isPalindrome(const string &s, int l, int r){
        int cnt = 0;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            cnt++;
            l--; r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++){
            count += isPalindrome(s, i, i); //odd
            count += isPalindrome(s, i, i+1); //even
        }
        return count;
    }

int main(){
    string s = "aaa";
    cout << countSubstrings(s) << endl;

    return 0;
}