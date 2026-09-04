#include<iostream>
#include<vector>
using namespace std;

int maxSum(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        if (n >= 1)
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
        }

        return dp[n];
    }

int main(){
    cout << maxSum(24) << endl;

    return 0;
}