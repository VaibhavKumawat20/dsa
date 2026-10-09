#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    typedef long long ll;

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, ll> events;

        for(auto& segment : segments){
            int st = segment[0];
            int end = segment[1];
            int color = segment[2];

            events[st] += color;
            events[end] -= color;
        }

        vector<vector<ll>> result;

        auto it = events.begin();
        int start = it->first;
        ll sum = it->second;

        it++;
        while(it != events.end()){
            if(sum > 0){
                result.push_back({start, it->first, sum});
            }

            start = it->first;
            sum += it->second;
            it++;
        }

        return result;
    }
};

int main(){
    Solution obj;

    vector<vector<int>> segments = {{1, 7, 9}, {6, 8, 15}, {8, 10, 7}};

    vector<vector<long long>> results = obj.splitPainting(segments);

    for(auto& result : results){
        cout << "{";
        for(int i : result){
            cout << i << " ";
        }
        cout << "}, ";
    }

    return 0;    
}