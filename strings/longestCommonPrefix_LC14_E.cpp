#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].compare(0, prefix.size(), prefix) != 0) {
                if (prefix.empty()) return "";
                prefix.pop_back();
            }
        }
        return prefix;
    }

    int main(){
        vector<string> strs = {"flower", "flow", "flight"};
        cout << longestCommonPrefix(strs) << endl;

        return 0;
    }