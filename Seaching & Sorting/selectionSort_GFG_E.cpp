#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr) {
        for(int i=0; i<arr.size(); i++){
            int min = i;
            for(int j=i; j<arr.size(); j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
    }

int main(){
    vector<int> arr = {64, 25, 12, 22, 11};

    selectionSort(arr);

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}