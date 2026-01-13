#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        // Your code goes here
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());
        
        for(int i=0; i<arr1.size(); i++){
            if(arr1[i]+arr2[i] < k){
                return false;
            }
        }
        return true;
    }

    int main(){
        vector<int> arr1 = {2, 1, 3, 1};
        vector<int> arr2 = {7, 8, 2, 9};
        int k = 10;

        cout << isPossible(k, arr1, arr2) << endl;

        return 0;
    }