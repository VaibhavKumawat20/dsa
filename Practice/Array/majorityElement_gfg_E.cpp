#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& arr) {
        // code here
        if(arr.empty()) return -1;
        
        int num = arr[0];
        int count = 1;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == num){
                count++;
            }
            else if(count == 0){
                num = arr[i];
                count = 1;
            }
            else{
                count--;
            }
        }
        count = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == num){
                count++; 
            }
        }
        if(count > arr.size()/2){
            return num;
        }
        else{
            return -1;
        }
    }

int main(){
    vector<int> arr = {1, 1, 2, 3, 2, 2, 5, 2, 4, 2, 2};

    cout << majorityElement(arr) << endl;

    return 0;
}