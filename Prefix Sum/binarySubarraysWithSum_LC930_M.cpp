#include<iostream>
#include<vector>
using namespace std;

int countSubarrays(vector<int> &nums, int goal){
        if(goal < 0) return 0;

        int l = 0, r = 0, sum = 0, cnt = 0;

        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarrays(nums, goal) - countSubarrays(nums, goal-1);
    }

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << numSubarraysWithSum(nums, goal) << endl;

    return 0;
}