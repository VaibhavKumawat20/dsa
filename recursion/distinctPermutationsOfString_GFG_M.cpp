#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string &s, int idx, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        bool used[256] = {false};

        for (int i = idx; i < s.size(); i++) {
            if (used[(unsigned char)s[i]])
                continue;

            used[(unsigned char)s[i]] = true;

            swap(s[idx], s[i]);
            solve(s, idx + 1, ans);
            swap(s[idx], s[i]);
        }
    }

vector<string> findPermutation(string &s) {
    vector<string> ans;
    solve(s, 0, ans);
    return ans;
}

int main(){
    string s = "ABC";

    vector<string> ans = findPermutation(s);

    for(string str : ans){
        cout << str << ", ";
    }
    cout << endl;

    return 0;
}