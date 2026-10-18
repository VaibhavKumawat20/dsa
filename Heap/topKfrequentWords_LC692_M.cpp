#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

// through sorting (T.C. - O(nlogn))
vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        // store frequency in map
        for(auto &word : words){
            mp[word]++;
        }

        // populate the vector with {word, freq}
        vector<pair<string, int>> vec;
        for(auto &it : mp){
            vec.push_back({it.first, it.second});
        }

        // sort the vector with comparator
        auto lambda = [](pair<string, int> &p1, pair<string, int> &p2){
            if(p1.second == p2.second)
                return p1.first < p2.first;
            
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        // return top K words
        vector<string> ans(k);
        int i = 0;
        while(i < k){
            ans[i] = vec[i].first;
            i++;
        }

        return ans;
    }

// through heap (T.C. - O(nlogk))


int main(){
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k = 4;

    vector<string> ans = topKFrequent(words, k);

    for(auto &i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}