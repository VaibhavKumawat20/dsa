#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& arr) {
        // Code here
        int maj1 = 0;
        int freq1 = 0;
        int maj2 = 1;
        int freq2 = 0;
        
        vector<int> ans;
        
        for(int x : arr){
            if(x == maj1){
                freq1++;
            }
            else if(x == maj2){
                freq2++;
            }
            else if(freq1 == 0){
                maj1 = x;
                freq1 = 1;
            }
            else if(freq2 == 0){
                maj2 = x;
                freq2 = 1;
            }
            else{
                freq1--;
                freq2--;
            }
        }
        
        freq1 = 0;
        freq2 = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == maj1)
                freq1++;
            else if(arr[i] == maj2)
                freq2++;
        }
        
        if(freq1 > (arr.size()/3))
            ans.push_back(maj1);
        if(freq2 > (arr.size()/3))
            ans.push_back(maj2);
            
        sort(ans.begin(), ans.end());
            
        return ans;
    }

int main(){
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};

    vector<int> ans = findMajority(arr);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}