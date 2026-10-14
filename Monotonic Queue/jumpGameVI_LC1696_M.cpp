#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        dq.push_back(n-1);

        for(int i=n-2; i>=0; i--){
            if(dq.front()-i > k)
                dq.pop_front();
            
            dp[i] = nums[i] + dp[dq.front()];
            while(dq.size() && dp[dq.back()]<dp[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return dp[0];
    }

int main(){
    vector<int> nums = {1,-1,-2,4,-7,3};
    int k = 2;

    cout << maxResult(nums, k) << endl;

    return 0;
}