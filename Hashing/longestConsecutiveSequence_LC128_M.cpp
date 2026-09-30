#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int longest = 1;
        unordered_set<int> st;
        for(int i : nums){
            st.insert(i);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x += 1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }

int main(){
    vector<int> nums = {101, 2, 100, 103, 4, 1, 3};

    cout << longestConsecutive(nums) << endl;

    return 0;
}