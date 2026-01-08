#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> paren;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            paren.push(s[i]);
        } 
        else {
            // 🔴 MUST check empty before top()
            if (paren.empty()) return false;

            if (
                (s[i] == ')' && paren.top() == '(') ||
                (s[i] == '}' && paren.top() == '{') ||
                (s[i] == ']' && paren.top() == '[')
            ) {
                paren.pop();
            } else {
                return false;
            }
        }
    }
    // 🔴 stack must be empty at the end
    return paren.empty();
    }

    int main(){
        string s = "({[]}[])";
        // string s = "({[]])";
        // string s = "({";
        bool isTrue = isValid(s);
        cout << isTrue << endl;

        return 0;
    }