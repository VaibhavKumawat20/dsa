#include<iostream>
using namespace std;

void printGfg(int N) {
    // Code here
    if(N == 0){
        return;
    }
    printGfg(N-1);
    cout << "GFG ";
}

int main(){
    int N;
    cout << "Enter N:";
    cin >> N;
    printGfg(N);

    return 0;
}
