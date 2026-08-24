#include<iostream>
using namespace std;

class Solution {
  public:
    int num = 1;
    int recursivePower(int n, int p) {
        // code here
        if(p == 0){
            return 1;
        }
        
        if(p == 1){
            num *= n;
            return num;
        }
        
        num *= n;
        return recursivePower(n, p-1);
    }
};


int main(){
    int n = 2;
    int p = 5;

    Solution obj;
    cout << obj.recursivePower(n, p) << endl;

    return 0;
}