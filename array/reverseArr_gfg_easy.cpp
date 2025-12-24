#include<iostream>
#include<vector>
using namespace std;

vector<int> reverseArray(vector<int> &arr) {
        // code here
        int j = arr.size()-1;
        for(int i=0; i<j; i++){
            swap(arr[i], arr[j--]);
        }
        return arr;
    }

    int main(){
        vector<int> arr = {1, 4, 3, 2, 6};
        vector<int> a = reverseArray(arr);

        for(int x : a){
            cout << x << " ";
        }

        return 0;
    }