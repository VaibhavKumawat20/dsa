#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& arr) {
        int count = 0;
        int candidate = -1;

        // Step 1: Find candidate
        for(int i = 0; i < arr.size(); i++){
            if(count == 0){
                candidate = arr[i];
            }
            if(arr[i] == candidate){
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify candidate (if arr not necessarily contains a majority element)
        count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == candidate){
                count++;
            }
        }

        if(count > arr.size() / 2){
            return candidate;
        }
        return -1;
    }

int main(){
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout << majorityElement(arr) << endl;

    return 0;
}