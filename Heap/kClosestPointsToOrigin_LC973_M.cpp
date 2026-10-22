#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for (auto &p : points) {
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.push({dist, p});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

int  main(){
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;

    vector<vector<int>> ans = kClosest(points, k);

    for (auto& a : ans) {
        cout << "[" << a[0] << ", " << a[1] << "]" << endl;
    }

    return 0;
}