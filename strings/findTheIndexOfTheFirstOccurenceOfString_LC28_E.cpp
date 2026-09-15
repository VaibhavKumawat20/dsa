#include<iostream>
#include<string>
using namespace std;

// bruteforce solution
int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0) return 0;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == m) {
                return i;
            }
        }

        return -1;
    }

// KMP solution


int main(){
    string haystack = "mississipi";
    string needle = "issip";

    cout << strStr(haystack, needle) << endl;

    return 0;
}