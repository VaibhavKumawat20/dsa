#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums){
            pq.push(num);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top(); //TC - O(n * log k)
    }

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    cout << findKthLargest(nums, k) << endl;

    return 0;
}