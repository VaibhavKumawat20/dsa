#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int> &nums){
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i : nums){
        if(currSum+i < 0){
            currSum = 0;
        }
        else{
            currSum += i;
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //vector<int> nums = {-2, 1, -3, 4};
    //vector<int> nums = {1};
    int ans = maxSubArray(nums);
    cout << ans;

    return 0;
}