#include<iostream>
#include<vector>
using namespace std;

void pushZerosToEnd(vector<int>& arr) {
        // code here
        int low = 0;
        int high = 1;
        
        if(arr.size() == 1){
            return;
        }
        
        while(high < arr.size()){
            if(arr[low] == 0 && arr[high] != 0){
                swap(arr[low], arr[high]);
            }
            else if(arr[low] == 0 && arr[high] == 0){
                high++;
            }
            else{
                low++; high++;
            }
        }

        //printing ans
        for(int i : arr){
            cout << i << " ";
        }
        cout << endl;
    }

int main(){
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};

    pushZerosToEnd(arr);

    return 0;
}