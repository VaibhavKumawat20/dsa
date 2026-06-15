#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int currSum = 0;
    int maxSum = INT_MIN;
        
    for(int i=0; i<arr.size(); i++){
        currSum = max(arr[i], currSum+arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main(){
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    cout << "Maximum subarray sum: " << maxSubarraySum(arr) << endl;

    return 0;
}