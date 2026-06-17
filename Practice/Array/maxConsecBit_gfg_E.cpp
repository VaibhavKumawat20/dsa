// logic cpmleted ele remaining
#include<iostream>
#include<vector>
using namespace std;

int maxConsecBits(vector<int> &arr) {
        // code here
        int count = 1;
        int maxCount = 0;
        if(arr.size() == 1){
            return 1;
        }
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        
        return max(maxCount, count);
    }

int main(){
    vector<int> arr = {0, 1, 0, 1, 1, 1, 1};
     
    cout << maxConsecBits(arr) << endl;

    return 0;
}