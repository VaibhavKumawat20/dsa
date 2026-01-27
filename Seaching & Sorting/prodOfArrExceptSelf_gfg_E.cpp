#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int> prefix(arr.size(), 1);
        int mul = 1;
        for(int i=1; i<arr.size(); i++){
            mul *= arr[i-1];
            prefix[i] = mul;
        }
        mul = 1;
        for(int i=arr.size()-2; i>=0; i--){
           mul *= arr[i+1];
           prefix[i] *= mul;
        }
        return prefix;
    }

int main(){
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> ans = productExceptSelf(arr);
    for(int i: ans){
        cout << i << ", ";
    }

    return 0;
}