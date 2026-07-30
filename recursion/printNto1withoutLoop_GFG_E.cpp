#include<iostream>
using namespace std;

void printNos(int n) {
        // code here
        if(n == 1){
            cout << n;
            return;
        }
        cout << n << " ";
        return printNos(n-1);
    }

int main(){
    printNos(10);

    return 0;
}