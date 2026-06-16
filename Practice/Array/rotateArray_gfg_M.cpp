#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArr(vector<int>& arr, int d) {
    // code here
    d = d%arr.size();
        
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());

    for(int i : arr){
        cout << i << " ";
    }
}

int main(){
    vector<int> arr = {2, 3, 7, 0};
    int d = 9;

    rotateArr(arr, d);

    return 0;
}