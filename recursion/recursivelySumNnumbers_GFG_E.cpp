#include<iostream>
using namespace std;

class Solution {
  public:
    int sum = 0;
    int recursiveSum(int n) {
        // Recursively sum from 1 to n and return
        // code here
        if(n == 0){
            return sum;
        }
        recursiveSum(n-1);
        sum += n;
        return sum;
    }
};

int main(){
    Solution obj;

    cout << obj.recursiveSum(5) << endl;

    return 0;
}