#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char, int> m;

        for(int i=0; i<s.length(); i++){
            char c = s[i];

            m[c]++;
            if(m[c] == 1){
                q.push(i);
            }

            while(q.size()>0 && m[s[q.front()]] > 1){
                q.pop();
            }
        }

        return (q.empty() ? -1 : q.front());
    }

int main(){
    string s = "leetcode";

    cout << firstUniqChar(s) << endl;

    return 0;
}