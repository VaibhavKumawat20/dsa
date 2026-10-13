#include<iostream>
#include<vector>
#include<Deque>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Maintain decreasing order in maxDeque
            while (!maxDeque.empty() &&
                   nums[maxDeque.back()] < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain increasing order in minDeque
            while (!minDeque.empty() &&
                   nums[minDeque.back()] > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Shrink window if difference exceeds limit
            while ((long long)nums[maxDeque.front()] -
                   nums[minDeque.front()] > limit) {
                if (maxDeque.front() == left)
                    maxDeque.pop_front();

                if (minDeque.front() == left)
                    minDeque.pop_front();

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

int main(){
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;

    cout << longestSubarray(nums, limit) << endl;

    return 0;
}