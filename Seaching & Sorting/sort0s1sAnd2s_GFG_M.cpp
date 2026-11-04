#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int>& arr) {
        int n0 = 0;
        int n1 = 0;
        int n2 = 0;
        
        for(int i : arr){
            if(i == 0) n0++;
            else if(i == 1) n1++;
            else n2++;
        }
        
        int i = 0;
        for(int j=0; j<n0; j++){
            arr[i++] = 0;
        }
        for(int j=0; j<n1; j++){
            arr[i++] = 1;
        }
        for(int j=0; j<n2; j++){
            arr[i++] = 2;
        }
    }

int main(){
    vector<int> arr = {2, 2, 1, 1, 0, 2, 1, 1, 0, 2, 2, 1, 0, 0, 1};

    sort012(arr);

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}