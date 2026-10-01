#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

        // 1. Count frequency
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // 2. Create buckets
        // bucket[i] contains numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto p : freq) {
            int number = p.first;
            int count = p.second;

            bucket[count].push_back(number);
        }

        // 3. Get top k elements
        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {

            for (int x : bucket[i]) {
                ans.push_back(x);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }

int main(){
    vector<int> nums = {1, 2, 1, 1, 2, 2, 3, 1, 3, 4};
    int k = 2;

    vector<int> ans =  topKFrequent(nums, k);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}