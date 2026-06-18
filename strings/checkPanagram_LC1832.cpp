#include<iostream>
#include<string>
using namespace std;

bool checkIfPangram(string sentence) {
        int freq[26];

        for(int i : sentence){
            freq[i - 97]++;
        }

        for(int i=0; i<26; i++){
            if(freq[i] == 0){
                return false;
            }
        }
        return true;
    }

int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    cout << checkIfPangram(sentence) << endl;

    return 0;
}