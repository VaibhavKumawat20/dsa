#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    private:
        int k;
        priority_queue<int, vector<int>, greater<int>> pq;

    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;

            for (int num : nums) {
                add(num);
            }
        }

        int add(int val) {
            pq.push(val);

            if (pq.size() > k) {
                pq.pop();
            }

            return pq.top();
        }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest kthLargest(k, nums);

    cout << kthLargest.add(3) << endl;  // 4
    cout << kthLargest.add(5) << endl;  // 5
    cout << kthLargest.add(10) << endl; // 5
    cout << kthLargest.add(9) << endl;  // 8
    cout << kthLargest.add(4) << endl;  // 8

    return 0;
}
