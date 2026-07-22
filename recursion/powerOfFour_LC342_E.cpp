#include<iostream>
using namespace std;

bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }
        if(n == 1){
            return true;
        }

        if(n%4 != 0){
            return false;
        }

        return isPowerOfFour(n/4);
    }

int main(){
    int n = 16;

    cout << isPowerOfFour(n) << endl;

    return 0;
}