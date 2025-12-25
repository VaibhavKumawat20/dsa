#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(), a.end());
        int i = 0;
        int j = i+(m-1);
        int diff = 0;
        int minDiff = INT_MAX;
        
        while(j < a.size()){
            diff = a[j] - a[i];
            minDiff = min(minDiff, diff);
            i++;
            j++;
        }
        return minDiff;
    }

int main(){
    vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    int ans = findMinDiff(a, m);

    cout << ans << endl;

    return 0;
}