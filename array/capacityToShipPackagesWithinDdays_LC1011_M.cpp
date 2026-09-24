#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int calculateDays(vector<int> &weights, int capacity){
        int currDays = 1;
        int currCap = 0;
        for(int i : weights){
            if(i + currCap > capacity){
                currDays++;
                currCap = i;
            }
            else{
                currCap += i;
            }
        }
        return currDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0;
        int low = INT_MIN;

        for(int i : weights){
            high += i;
            low = max(i, low);
        }

        while(low < high){
            int mid = low + (high-low)/2;

            int currDays = calculateDays(weights, mid);

            if(currDays > days) low = mid+1;
            else high = mid;
        }

        return low;
    }

int main(){
    vector<int> weights  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << shipWithinDays(weights, days) << endl;

    return 0;
}