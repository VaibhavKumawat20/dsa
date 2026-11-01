#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int toyCount(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int count = 0, sum = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(sum + arr[i] <= k) {
                sum += arr[i];
                count++;
            }
            else {
                break;
            }
        }

        return count;
    }

int main(){
    vector<int> arr = {1, 12, 5, 111, 200, 1000, 10};
    int k = 50;

    cout << toyCount(arr, k) << endl;

    return 0;
}