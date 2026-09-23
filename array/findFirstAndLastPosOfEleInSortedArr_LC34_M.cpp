#include<iostream>
#include<vector>
using namespace std;

int searchLeftPos(vector<int> &nums, int target){
        int index = -1;
        int st = 0;
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(target == nums[mid]){
                index = mid;
                end = mid-1;
            }

            else if(nums[mid] < target){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return index;
    }

    int searchRightPos(vector<int> &nums, int target){
        int index = -1;
        int st = 0;
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(target == nums[mid]){
                index = mid;
                st = mid+1;
            }

            else if(nums[mid] < target){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = searchLeftPos(nums, target);
        int right = searchRightPos(nums, target);

        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }

int main(){
    vector<int> nums = {6, 7, 8, 8, 8, 9, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}