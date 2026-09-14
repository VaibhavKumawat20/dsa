#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0; int r = numbers.size()-1;
        vector<int> ans;

        while(l < r){
            int sum = numbers[l] + numbers[r];

            if(sum == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }

int main(){
    vector<int> numbers = {2, 3, 4, 6, 8, 11};
    int target = 12;

    vector<int> ans = twoSum(numbers, target);

    cout << "Output: [";
    for(int i : ans){
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}