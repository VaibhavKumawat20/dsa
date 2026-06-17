#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int>& arr) {
        // code here
        int max = INT_MIN;
        vector<int> ans;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i] >= max){
                ans.push_back(arr[i]);
                max = arr[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};

    vector<int> ans = leaders(arr);

    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}