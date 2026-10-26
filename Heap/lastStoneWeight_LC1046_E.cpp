#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// // Sorting approach --> T.C. - O(n * nlogn)
// int lastStoneWeight(vector<int>& stones) {
//         while(stones.size() > 1){
//             sort(begin(stones), end(stones));

//             int a = stones.back(); stones.pop_back();
//             int b = stones.back(); stones.pop_back();

//             stones.push_back(abs(a-b));
//         }

//         return stones[0];
//     }

// Max Heap approach --> T.C. - O(nlogn)
int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int stone : stones){
            pq.push(stone);
        }

        while(pq.size() > 1){
            int a = pq.top(); 
            pq.pop();

            int b = pq.top();
            pq.pop();

            pq.push(abs(a-b));
        }

        return pq.top();
    }

int main(){
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << lastStoneWeight(stones) << endl;

    return 0;
}