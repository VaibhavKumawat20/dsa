#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int search = 3;

    int st = 0; int end = sizeof(arr)/sizeof(int);

    while(st < end){
        int mid = st + (end-st)/2;

        if(arr[mid] == search){
            cout << "Position at : " << mid << endl;
            return 0;
        }

        if(arr[mid] > search){
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }

    cout << "No element found!" << endl;
    return 0;
}