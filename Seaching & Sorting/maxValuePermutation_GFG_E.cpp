#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxValue(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            ans += (arr[i] * i);
        }
        
        return ans;
    }

int main(){
    vector<int> arr = {4, 2, 5, 3, 1};

    cout << maxValue(arr) << endl;

    return 0;
}