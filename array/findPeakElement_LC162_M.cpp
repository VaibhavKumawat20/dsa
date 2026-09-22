#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak lies on the right
                st = mid + 1;
            } 
            else {
                // Peak is at mid or on the left
                end = mid;
            }
        }

        return st;
    }

int main(){
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    cout << findPeakElement(nums) << endl;

    return 0;
}