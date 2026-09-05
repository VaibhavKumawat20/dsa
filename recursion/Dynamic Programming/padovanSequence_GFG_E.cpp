#include<iostream>
using namespace std;

int padovanSequence(int n) {
        // code here
        int modul  = 1e9 + 7;
        
        int a = 1;
        int b = 1;
        int c = 1;
        int padS = c;
        
        for(int i=3; i<=n; i++){
            padS = (b + a)%modul;
            a = b%modul;
            b = c%modul;
            c = padS%modul;
        }
        
        return padS%modul;
    }

int main(){
    cout << padovanSequence(6) << endl;

    return 0;
}