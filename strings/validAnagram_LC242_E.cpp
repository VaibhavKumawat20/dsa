#include<iostream>
using namespace std;

bool isAnagram(string s, string t) {
        int s_freq[26] = {0};
        int t_freq[26] = {0};

        for(int i=0; i<s.size(); i++){
            s_freq[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++){
            t_freq[t[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(s_freq[i] != t_freq[i]){
                return false;
            }
        }
        return true;
    }

    int main(){
        string s = "anagram";
        string t = "nagaram";
        bool B = isAnagram(s, t);
        cout << B << endl;

        return 0;
    }