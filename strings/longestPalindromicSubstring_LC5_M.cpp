#include<iostream>
#include<vector>
using namespace std;
    
    int start = 0;
    int maxLen = 1;

    void expandFromCenter(const string &s, int left, int right) {
        int n = s.length();

        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes (center at i)
            expandFromCenter(s, i, i);

            // Even-length palindromes (center between i and i+1)
            expandFromCenter(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }

int main(){
    string s = "cdabdbakld";
    // string s = "cdabbakld";
    cout << longestPalindrome(s) << endl;

    return 0;
}