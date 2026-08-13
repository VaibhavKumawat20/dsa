#include<iostream>
#include<vector>
using namespace std;

int perfectSum(vector<int>& arr, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int x : arr) {
            for (int sum = target; sum >= x; --sum) {
                dp[sum] += dp[sum - x];
            }
        }

        return dp[target];
    }

int main(){
    vector<int> arr = {5, 2, 3, 10, 6, 8};

    cout << perfectSum(arr, 10) << endl;

    return 0;
}