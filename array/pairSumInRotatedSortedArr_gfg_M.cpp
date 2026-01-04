#include<iostream>
#include<vector>
using namespace std;

bool pairInSortedRotated(vector<int>& arr, int target) {
    int n = arr.size();
    int i;

    // Find pivot
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            break;
        }
    }

    int large = i;           // index of largest element
    int small = (i + 1) % n; // index of smallest element

    while (large != small) {
        int sum = arr[large] + arr[small];

        if (sum == target)
            return true;

        if (sum > target)
            large = (large - 1 + n) % n;
        else
            small = (small + 1) % n;
    }

    return false;
}

int main(){
    vector<int> arr = {7, 9, 1, 3, 5};
    int target = 6;
    bool SumExists = pairInSortedRotated(arr, target);
    cout << SumExists << endl;

    return 0;
}