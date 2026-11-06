#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx = st - 1; 
    int pivot = arr[end];

    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){ // for array in decreasing order --> if(arr[j] >= pivot){} ... rest all code same 
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);

    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st < end){
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx-1); // Left half
        quickSort(arr, pivIdx+1, end); // Right half
    }
}

int main(){
    vector<int> arr = {5, 2, 6, 4, 1, 3};

    quickSort(arr, 0, arr.size()-1);

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}