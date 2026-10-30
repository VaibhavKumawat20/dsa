#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
        for(int i=1; i<arr.size(); i++){
            for(int j=i; j>0; j--){
                if(arr[j] < arr[j-1]){
                    swap(arr[j], arr[j-1]);
                }
            }
        }
    }

int main(){
    vector<int> arr = {12, 11, 13, 5, 6};

    insertionSort(arr);

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}