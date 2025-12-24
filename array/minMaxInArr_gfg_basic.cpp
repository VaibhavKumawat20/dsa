#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> getMinMax(vector<int> &arr) {
        // code here
        int min = INT_MAX;
        int max = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < min){
                min = arr[i];
            }
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return {min, max};
    }

int main(){
    vector<int> arr = {1, 4, 3, -5, -4, 8, 6};
    vector<int> a = getMinMax(arr);

    for (int x : a) {
    cout << x << " ";
    }

    return 0;
}