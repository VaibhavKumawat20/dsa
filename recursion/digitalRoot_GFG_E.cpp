#include<iostream>
using namespace std;

int solve(int n){
        int sum = 0;
        while(n != 0){
            sum += n%10;
            n /= 10;
        }    
        return sum;
    }
    
    int digitalRoot(int n) {
        // code here
        if(n/10 == 0){
            return n;
        }
        
        n = solve(n);
        
        return digitalRoot(n);
    }

int main(){
    int n = 99999;
    cout << digitalRoot(n) << endl;

    return 0;
}