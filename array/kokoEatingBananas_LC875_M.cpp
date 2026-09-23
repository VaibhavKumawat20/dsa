#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateHours(vector<int>& piles, int k) {
        int totHrs = 0;

        for (int i : piles) {
            totHrs += (i + k - 1) / k;
        }

        return totHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;

        for (int i : piles) {
            maxi = max(maxi, i);
        }

        int low = 1;
        int high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int currHrs = calculateHours(piles, mid);

            if (currHrs > h) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }

int main(){
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}