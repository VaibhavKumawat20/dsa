#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0, j=0, k=0;
        vector<int> ans;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
            if(arr1[i] == arr2[j] && arr2[j]==arr3[k]){
                if(ans.empty() || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++; j++; k++;
            }
            else{
                int minimum = min({arr1[i], arr2[j], arr3[k]});
                if(arr1[i]==minimum){
                    i++;
                }
                else if(arr2[j]==minimum){
                    j++;
                }
                else{
                    k++;
                }
            }
            
        }
        if(ans.empty()){
            ans.push_back(-1);
            return ans;
        }
        return ans;
    }

int main(){
    vector<int> arr1 = {10, 20, 30, 50, 80, 100};
    vector<int> arr2 = {8, 20, 35, 55, 80, 90};
    vector<int> arr3 = {10, 20, 30, 40, 80, 100};

    vector<int>ans = commonElements(arr1, arr2, arr3);
    for(int i : ans){
        cout << i << ", ";
    }

    return 0;
}