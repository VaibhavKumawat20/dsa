#include<iostream>
#include<string>
#include<stack>
using namespace std;

// // Two stack solution
// bool backspaceCompare(string s, string t) {
//         stack<char> s1;
//         stack<char> t1;

//         for(char c : s){
//             if(c == '#'){
//                 if(!s1.empty())
//                     s1.pop();
//             }
//             else if(c != '#'){
//                 s1.push(c);
//             }
//         }

//         for(char c : t){
//             if(c == '#'){
//                 if(!t1.empty())
//                     t1.pop();
//             }
//             else if(c != '#'){
//                 t1.push(c);
//             }
//         }

//         if(s1 == t1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }

// Two pointer approach
bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {

            // Find the next valid character in s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS > 0) {
                    skipS--;
                    i--;
                }
                else {
                    break;
                }
            }

            // Find the next valid character in t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }

            // If both pointers are valid, compare characters
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            }
            // If one string has a character left and the other doesn't
            else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }

int main(){
    string s = "y#fo##f";
    string t = "y#f#o##f";

    bool b = backspaceCompare(s, t);

    cout << b << endl;

    return 0;
}