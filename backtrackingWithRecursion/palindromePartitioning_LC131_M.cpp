#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalin(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1); //left part

            if(isPalin(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans); // right part
                partitions.pop_back(); //backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<vector<string>> ans = obj.partition(s);

    cout << "\nPalindrome Partitions:\n";

    for(auto &partition : ans){
        cout << "[ ";
        for(auto &part : partition){
            cout << part << " ";
        }
        cout << "]\n";
    }

    return 0;
}