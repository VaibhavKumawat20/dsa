#include<iostream>
#include<vector>
using namespace std;

int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        int i = 0;
        while(i<arr.size()){
            if(arr[i] == x){
                return i;
            }
            int diff = abs(x-arr[i]);
            int iterate = diff/k;
            iterate = max(iterate, 1);
            i += iterate;
        }
        return -1;
    }

int main(){
    vector<int> arr = {20, 30, 50, 70, 50};
    int k = 20;
    int x = 50;

    cout << findStepKeyIndex(arr, k, x) << endl;

    return 0;
}