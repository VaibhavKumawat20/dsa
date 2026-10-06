#include<iostream>
#include<vector>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diffArr[1001] = {0};

        for(auto& trip : trips){
            int count = trip[0];
            int start = trip[1];
            int end = trip[2];

            diffArr[start] += count;
            diffArr[end] -= count;
        }

        int cummSum = 0;

        for(int i=0; i<1001; i++){
            cummSum += diffArr[i];

            if(cummSum > capacity){
                return false;
            }
        }

        return true;
    }

int main(){
    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;

    cout << carPooling(trips, capacity) << endl;

    return 0;
}