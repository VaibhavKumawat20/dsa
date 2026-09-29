#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;

int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxLen = 0;
        map<int, int> mp;

        while(r < fruits.size()){
            mp[fruits[r]]++;

            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }

            if(mp.size() <= 2){
                maxLen = max(maxLen, r-l + 1);
            }
            r++;
        }

        return maxLen;
    }

int main(){
    vector<int> fruits = {2, 2, 2, 3, 4, 1, 4, 4, 1, 5, 3};

    cout << totalFruit(fruits) << endl;

    return 0;
}