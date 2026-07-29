#include<iostream>
using namespace std;

class Solution {
  public:
    int count = 0;
    int countDigits(int n) {
        // Code here
        count++;
        if(n/10 == 0){
            return count;
        }
        
        return countDigits(n/10);
    }
};

int main(){
    Solution obj;
    cout << obj.countDigits(18809567) << endl;

    return 0;
}