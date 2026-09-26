#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int calculateBouquets(vector<int> &bloomDay, int flowers, int day){
        int currBloomDays = 0;
        int count = 0;
        for(int i : bloomDay){
            if(day >= i){
                count++;
                if(count == flowers){
                    currBloomDays++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }

        return currBloomDays;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i : bloomDay){
            low = min(i, low);
            high = max(i, high);
        }

        while(low <= high){
            int mid = low + (high-low)/2;

            int currBouquets = calculateBouquets(bloomDay, k, mid);

            if(currBouquets < m){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;
    }

int main(){
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 2;
    int k = 3;

    cout << minDays(bloomDay, m, k) << endl;

    return 0;
}