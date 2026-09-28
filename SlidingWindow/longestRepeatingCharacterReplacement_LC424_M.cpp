#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int low = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int high = 0; high < s.length(); high++) {
            freq[s[high] - 'A']++;

            maxFreq = max(maxFreq, freq[s[high] - 'A']);

            // Characters that need to be replaced
            int replacements = (high - low + 1) - maxFreq;

            while (replacements > k) {
                freq[s[low] - 'A']--;
                low++;

                replacements = (high - low + 1) - maxFreq;
            }

            ans = max(ans, high - low + 1);
        }

        return ans;
    }

int main(){
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k) << endl;

    return 0;
}