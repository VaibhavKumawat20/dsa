#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix;

public:
    // Constructor
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    // Returns sum from index left to right
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    // Example array
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    // Create NumArray object
    NumArray obj(nums);

    // Test queries
    cout << obj.sumRange(0, 2) << endl; // 1
    cout << obj.sumRange(2, 5) << endl; // -1
    cout << obj.sumRange(0, 5) << endl; // -3

    return 0;
}
