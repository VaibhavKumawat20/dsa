#include<iostream>
using namespace std;

int nthFibonacci(int n) {
        // code here
        int c, a, b;
        a = 0;
        b = 1;
        c = 0;
        
        if(n == 1){
            return 1;
        }
        
        for(int i=2; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        
        return c;
    }


int main(){
    cout << nthFibonacci(5) << endl;

    return 0;
}