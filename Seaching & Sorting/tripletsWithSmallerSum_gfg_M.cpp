#include <iostream>
#include <algorithm>
using namespace std;

long long countTriplets(int n, long long sum, long long arr[]) {
    sort(arr, arr + n);

    long long ans = 0;

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;

        while (j < k) {
            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;
            else {
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}

int main() {
    long long arr[] = {5, 1, 3, 4, 7};
    long long sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countTriplets(n, sum, arr) << endl;
    return 0;
}
