#include<iostream>
#include<string>
using namespace std;

string sortString(string &s) {
        int arr[26] = {0};
        for(int i=0; i<s.length(); i++){
            arr[s[i] - 'a']++;
        }
        
        s = "";
        
        for(int i=0; i<26; i++){
            while(arr[i] > 0){
                s += char('a' + i);
                arr[i]--;
            }
        }
        
        return s;
    }

int main(){
    string s = "bdeac";

    cout << sortString(s) << endl;

    return 0;
}