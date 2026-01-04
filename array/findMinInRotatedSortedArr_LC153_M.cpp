#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end]) {
                st = mid + 1;   // min is in right half
            } else {
                end = mid;      // min is in left half
            }
        }
        return nums[st];
    }

    int main(){
        vector<int> nums = {3, 4, 5, 1, 2};
        int ans = findMin(nums);
        cout << ans << endl;

        return 0;
    }