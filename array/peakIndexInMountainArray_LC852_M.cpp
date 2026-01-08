#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size()-2;
        
        while(st <= end){
            int mid = st + (end-st)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            if(arr[mid] > arr[mid-1])
                st = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }

    int main(){
        vector<int> arr = {3, 4, 5, 10, 0};
        int index = peakIndexInMountainArray(arr);
        cout << index << endl;

        return 0;
    }