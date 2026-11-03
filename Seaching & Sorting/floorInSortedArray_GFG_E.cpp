#include<iostream>
#include<vector>
using namespace std;

int findFloor(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] <= x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

int main(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;

    cout << findFloor(arr, x) << endl;

    return 0;
}