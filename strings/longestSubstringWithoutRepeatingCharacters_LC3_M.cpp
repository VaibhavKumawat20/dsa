#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

// // O(n^2) solution
// int lengthOfLongestSubstring(string s) {
//         string ans = "";
//         int size = 0;

//         for(int i=0; i<s.length(); i++){
//             ans += s[i];
//             for(int j=i+1; j<s.length(); j++){
//                 if(ans.contains(s[j]))
//                     break;
//                 else
//                     ans += s[j];
//             }
//             if(size < ans.length())
//                 size = ans.length();
            
//             ans = "";
//         }
//         return size;
//     }

// O(n) solution -> sliding window
int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Duplicate found
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Calculate current window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }

int main(){
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}