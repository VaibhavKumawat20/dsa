#include<iostream>
#include<vector>
using namespace std;

// without recursion
vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits)
            freq[d]++;

        vector<int> ans;

        for (int num = 100; num <= 998; num += 2) {

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool ok = true;

            for (int i = 0; i < 10; i++) {
                if (need[i] > freq[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(num);
        }

        return ans;
    }

int main(){
    vector<int> digits = {3, 1, 0, 2};

    vector<int> ans = findEvenNumbers(digits);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}