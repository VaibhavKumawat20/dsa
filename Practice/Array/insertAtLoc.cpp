#include<iostream>
#include<vector>
using namespace std;

void insertAtLocation(vector<int> &arr, int loc, int value){
    arr.push_back(0);
    int n = arr.size();
    int i;
    for(i=n-1; i>loc; i--){
        arr[i] = arr[i-1];
    }
    arr[loc] = value;

    for(int j=0; j<n; j++){
        cout << arr[j] << " ";
    }
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 6, 7};
    int loc = 4;
    int value = 5;

    insertAtLocation(arr, loc, value);

    return 0;
}