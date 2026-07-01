#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        unordered_map<int, int> m;

        for(int i=nums2.size()-1; i>=0; i--){
            if(s.empty()){
                m[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            while(s.top() < nums2[i]){
                s.pop();
                if(s.empty()){
                    m[nums2[i]] = -1;
                    s.push(nums2[i]);
                    break;
                }
            }
            if(s.top() > nums2[i]){
                m[nums2[i]] = s.top();
                s.push(nums2[i]);
            }
        }
        for(int x : nums1){
            ans.push_back(m[x]);
        }
        return ans;
    }

int main(){
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}