#include<iostream>
#include<vector>
using namespace std;

void segregate0and1(vector<int> &arr) {
        // code here
        int low = 0;
        int high = 1;
        
        while(high < arr.size()){
            if(arr[low] == 1 && arr[high] == 0){
                swap(arr[low], arr[high]);
            }
            else if(arr[low] == 1 && arr[high] == 1){
                high++;
            }
            else{
                low++; high++;
            }
        }

        for(int i : arr){
            cout << i << " ";
        }
        cout << endl;
    }

int main(){
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};

    segregate0and1(arr);

    return 0;
}