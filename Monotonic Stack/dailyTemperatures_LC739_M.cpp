#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(st.empty()){
                res[i] = 0;
            }
            else{
                res[i] = st.top()-i;
            }

            st.push(i);
        }

        return res;
    }

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> ans = dailyTemperatures(temperatures);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}