#include<iostream>
#include<string>
using namespace std;

string countSort(string s) {
        // code here
        int count[26] = {0};
        
        for(int i=0; i<s.length(); i++){
            count[s[i]-'a']++;
        }
        
        string ans = "";
        for(int i=0; i<26; i++){
            while(count[i]--){
                ans += char(i + 'a');
            }
        }
        return ans;
    }

    int main(){
        string s = "geeksforgeeks";
        cout << countSort(s) << endl;

        return 0;
    }