#include<iostream>
using namespace std;

int main(){
    int arr[] = {3, 5, 1, 2, 4};
    int n = sizeof(arr);

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "[" ;
    for(int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;

    return 0;
}
