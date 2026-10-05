#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = 1;

        int res = 0;

        for(int i : nums){
            sum += i;

            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end()){
                res += mp[rem];
            }

            mp[rem]++;
        } 

        return res;
    }

int main(){
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << subarraysDivByK(nums, k) << endl;

    return 0;
}