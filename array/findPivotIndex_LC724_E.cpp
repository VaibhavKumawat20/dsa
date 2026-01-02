#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i=1; i<n; i++){
            ans[i] = nums[i-1] + ans[i-1];
        }

        int check = 0, idx = -1;
        for(int i=n-1; i>=0; i--){
            if(check == ans[i]){
                idx = i;
            }
            check = nums[i] + check;
        }
        return idx;
    }

    int main(){
        vector<int> nums = {1, 7, 3, 6, 5, 6};
        //vector<int> nums = {-1, -1, 0, 1, 1, 0};

        int ans = pivotIndex(nums);
        cout << ans << endl;

        return 0;
    }