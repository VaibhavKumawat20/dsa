#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool findPair(vector<int> &arr, int x) {
        int n = arr.size();
        if (n < 2) return false;
    
        sort(arr.begin(), arr.end());
    
        int i = 0, j = 1;
    
        while (i < n && j < n) {
            if (i != j && arr[j] - arr[i] == x)
                return true;
            else if (arr[j] - arr[i] < x)
                j++;
            else
                i++;
    
            if (i == j) j++;
        }
        return false;
    }

int main(){
    vector<int> arr = {5, 2, 3, 80, 20, 5};
    int x = 78;

    cout << findPair(arr, x) << endl;

    return 0;
}