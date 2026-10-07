#include<iostream>
#include<vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n + 1, 0);

        for (auto &booking : bookings) {
            int st = booking[0];
            int end = booking[1];
            int cnt = booking[2];

            ans[st-1] += cnt;
            ans[end] -= cnt;
        }

        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }

        ans.pop_back();
        return ans;
    }

int main(){
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;

    vector<int> ans = corpFlightBookings(bookings, n);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}