#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                return true;
            }
        }
        return false;
    }

int main(){
    vector<int> nums = {1, 2, 3, 1};
    bool isDuplicate = containsDuplicate(nums);
    cout << isDuplicate << endl;

    return 0;
}