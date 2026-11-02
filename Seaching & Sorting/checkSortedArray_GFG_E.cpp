#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr) {
        // code here
        if(arr.size() == 1) return true;
        
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] > arr[i+1]) return false;
        }
        
        return true;
    }

int main(){
    vector<int> arr = {1, 2, 3, 5, 4};

    cout << isSorted(arr) << endl;

    return 0;
}