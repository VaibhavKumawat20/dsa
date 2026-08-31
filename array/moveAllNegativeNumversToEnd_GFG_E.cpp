#include<iostream>
#include<vector>
using namespace std;

void segregateElements(vector<int>& arr) {
        // code here
        vector<int> temp;
        
        for(int i : arr){
            if(i >= 0){
                temp.push_back(i);
            }
        }
        for(int i : arr){
            if(i < 0){
                temp.push_back(i);
            }
        }
        
        for(int i=0; i<arr.size(); i++){
            arr[i] = temp[i];
        }
    }

int main(){
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};

    segregateElements(arr);

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}