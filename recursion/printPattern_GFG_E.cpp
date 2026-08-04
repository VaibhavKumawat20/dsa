#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> ans;
    
    vector<int> pattern(int n) {
        if(n <= 0){
            ans.push_back(n);
            return ans;
        }
        ans.push_back(n);
        
        pattern(n - 5);
        
        if(n > 0)
            ans.push_back(n);
        return ans;
    }
};

int main(){
    Solution obj;
    int n = 16;

    vector<int> res = obj.pattern(n); 
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}