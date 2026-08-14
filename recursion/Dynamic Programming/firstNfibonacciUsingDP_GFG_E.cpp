#include<iostream>
#include<vector>
using namespace std;

vector<int> fibonacciNumbers(int n) {
        const int MOD = 1e9 +7;
        
        vector<int> fib(n+1);
        
        fib[0] = 0;
        fib[1] = 1;
        
        for(int i=2; i<=n; i++){
            fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        }
        
        return fib;
    }

int main(){
    vector<int> ans = fibonacciNumbers(5);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}