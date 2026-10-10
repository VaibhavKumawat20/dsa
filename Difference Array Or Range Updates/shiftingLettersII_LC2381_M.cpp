#include<iostream>
#include<vector>
#include<string>
using namespace std;

string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);

        for (auto& shift : shifts) {
            int st = shift[0];
            int end = shift[1];
            int dir = shift[2];

            int val = (dir == 1) ? 1 : -1;

            diff[st] += val;
            diff[end + 1] -= val;
        }

        int curr = 0;

        for (int i = 0; i < n; i++) {
            curr += diff[i];

            int shift = ((curr % 26) + 26) % 26;

            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }

int main(){
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};

    cout << shiftingLetters(s, shifts) << endl;

    return 0;
}