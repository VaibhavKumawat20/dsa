#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &ans, int n){
        if(n == 0){
            return;
        }
        if(n == 1){
            ans.push_back(0);
            return;
        }
        if(n == 2){
            ans.push_back(0);
            ans.push_back(1);
            return;
        }
        
        solve(ans, n-1);
        
        int sz = ans.size();
        int next = ans[sz-2]*ans[sz-2] - ans[sz-1];
        ans.push_back(next);
    }
  
    vector<int> gfSeries(int n) {
        // code here
        vector<int> ans;
        solve(ans, n);
        
        return ans;
    }

int main(){
    vector<int> ans;
    ans = gfSeries(6);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}