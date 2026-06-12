//completed
#include<iostream>
#include<vector>
using namespace std;

void deleteAtLocation(vector<int> &arr, int loc, int value){
    int n = arr.size();

    for(int i=loc; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr.pop_back();

    for(int j=0; j<n-1; j++){
        cout << arr[j] << " ";
    }
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7};
    int loc = 4;
    int value = 5;

    deleteAtLocation(arr, loc, value);

    return 0;
}