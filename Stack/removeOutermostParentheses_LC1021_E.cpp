#include<iostream>
#include<string>
#include<stack>
using namespace std;

string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        if(s.length() == 0){
            return s;
        }

        for(char c : s){
            if(c == '('){
                if(st.empty()){
                    st.push('(');
                }
                else{
                    st.push('(');
                    ans += '(';
                }
            }
            else{
                if(st.size() == 1){
                    st.pop();
                }
                else{
                    st.pop();
                    ans += ')';
                }
            }
        }

        return ans;
    }

int main(){
    string s = "(()())(())(()(()))";

    cout << removeOuterParentheses(s) << endl;

    return 0;
}