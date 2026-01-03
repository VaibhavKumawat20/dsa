#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int minProd = 1;
        int maxProd = 1;

        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                swap(maxProd, minProd);
            }
            maxProd = max(maxProd*nums[i], nums[i]);
            minProd = min(minProd*nums[i], nums[i]);

            ans = max(ans, maxProd);
        }

        return ans;
    }

    int main(){
        vector<int> nums = {3, -2, -4, -5, 3};

        int ans = maxProduct(nums);

        cout << ans << endl;

        return  0;
    }