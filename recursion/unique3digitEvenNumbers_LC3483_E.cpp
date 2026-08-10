#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;

    void solve(vector<int>& digits, vector<bool>& used, int pos) {
        if (pos == 3) {
            ans++;
            return;
        }

        set<int> seen;

        for (int i = 0; i < digits.size(); i++) {
            if (used[i])
                continue;

            // Avoid duplicate digits at the same position
            if (seen.count(digits[i]))
                continue;

            // First digit cannot be 0
            if (pos == 0 && digits[i] == 0)
                continue;

            // Last digit must be even
            if (pos == 2 && digits[i] % 2 != 0)
                continue;

            seen.insert(digits[i]);

            used[i] = true;
            solve(digits, used, pos + 1);
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);
        solve(digits, used, 0);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> digits = {1, 2, 3, 4};
    // vector<int> digits = {0, 2, 2};

    cout << obj.totalNumbers(digits) << endl;

    return 0;
}