#include<iostream>
#include<vector>
using namespace std;

int sumExceptFirstLast(vector<int>& arr) {
        // code here
        int sum = 0;
        for(int i=1; i<arr.size()-1; i++){
            sum += arr[i];
        }
        
        return sum;
    }

int main(){
    vector<int> arr = {5, 24, 39, 60, 15, 28, 27, 40, 50, 90};

    cout << sumExceptFirstLast(arr) << endl;

    return 0;
}