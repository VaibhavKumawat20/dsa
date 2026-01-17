#include<iostream>
#include<vector>
using namespace std;

int findCeil(vector<int>& arr, int x) {
        // code here
        int ans = -1;
        int st = 0;
        int end = arr.size()-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            
            if(arr[mid]>=x){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }

int main(){
    vector<int> arr = {1, 2, 8, 10, 11, 19, 20};
    int x = 5;
    cout << findCeil(arr, x) << endl;

    return 0;
}