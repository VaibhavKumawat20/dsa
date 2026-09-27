#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int high = 0; high < nums.size(); high++) {
            sum += nums[high];

            while (sum >= target) {
                ans = min(ans, high - low + 1);
                sum -= nums[low];
                low++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }

int main(){
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}