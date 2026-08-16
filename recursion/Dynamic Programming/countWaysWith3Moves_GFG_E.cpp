#include<iostream>
using namespace std;


int countWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int a = 1;
        int b = 1;
        int c = 2;
        
        for(int i=3; i<=n; i++){
            int d = a+b+c;
            a = b;
            b = c;
            c = d;
        }
        
        return c;
    }

int main(){
    cout << countWays(3) << endl;

    return 0;
}