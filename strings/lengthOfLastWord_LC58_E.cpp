#include<iostream>
#include<string>
using namespace std;

// // from begining
// int lengthOfLastWord(string s) {
//         int ans = 0;
//         int currLen = 0;

//         for(int i=0; i<s.length(); i++){
//             if(s[i] == ' '){
//                 if(currLen > 0){
//                     ans = currLen;
//                     currLen = 0;
//                 }
//             }
//             else{
//                 currLen++;
//             }
//         }
//         if(currLen > 0){
//             ans = currLen;
//         }
//         return ans;
//     }


// from end
int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.length() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }

        return ans;
    }
    
int main(){
    string s = "  fly me  to  the moon  ";
    cout << lengthOfLastWord(s) << endl;

    return 0;
}