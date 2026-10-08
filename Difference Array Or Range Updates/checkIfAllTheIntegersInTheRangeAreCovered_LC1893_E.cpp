#include<iostream>
#include<vector>
using namespace std;

bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int diff[52] = {};

        // Mark the start and end of every interval
        for (auto &range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }

        // Calculate coverage
        int count = 0;

        for (int i = 1; i <= right; i++) {
            count += diff[i];

            if (i >= left && count == 0)
                return false;
        }

        return true;
    }

int main(){
    vector<vector<int>> ranges = {{1, 2}, {3, 4}, {5, 6}};
    int left = 2;
    int right = 5;

    cout << isCovered(ranges, left, right) << endl;

    return 0;
}