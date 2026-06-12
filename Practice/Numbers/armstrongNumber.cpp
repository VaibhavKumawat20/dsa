//completed
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0, temp, freq = 0;

    temp = n;

    // Count digits
    while (temp) {
        freq++;
        temp /= 10;
    }

    temp = n;

    // Calculate sum of digits raised to the power of digit count
    while (temp) {
        sum += round(pow(temp % 10, freq));
        temp /= 10;
    }

    if (sum == n) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}