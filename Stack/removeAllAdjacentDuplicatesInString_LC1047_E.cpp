#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
        stack<char> st;

        string ans = "";

        for(char c : s){
            if(!st.empty() && c != st.top()){
                st.push(c);
            }
            else if(!st.empty() && c == st.top()){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){
    string s = "abbaca";

    cout << removeDuplicates(s) << endl;

    return 0;
}