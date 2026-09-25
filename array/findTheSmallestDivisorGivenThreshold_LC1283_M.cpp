#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int calculateDivisorSum(vector<int> &nums, int mid)
{
    int sum = 0;
    for (int i : nums)
    {
        sum += (i + mid - 1) / mid;
    }
    return sum;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = INT_MIN;

    for (int i : nums)
    {
        high = max(i, high);
    }

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        int sum = calculateDivisorSum(nums, mid);

        if (sum > threshold)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main(){
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << smallestDivisor(nums, threshold) << endl;

    return 0;
}