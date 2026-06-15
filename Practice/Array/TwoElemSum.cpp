// (can also be done hash map)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        
        int low = 0;
        int high = arr.size()-1;
        
        while(low < high){
            if(arr[low]+arr[high] == target){
                return true;
            }
            else if(arr[low]+arr[high] > target){
                high--;
            }
            else{
                low++;
            }
        }
        return false;
    }

int main(){
    vector<int> arr = {2, 4, 1, 6, 3};
    int sum = 10;

    cout << twoSum(arr, sum) << endl;

    return 0;
}