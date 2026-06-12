//completed
#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter num:";
    cin >> num;

    int sq = num*num;

    while(num){
        int numR, sqR;

        numR = num%10;
        sqR = sq%10;

        if(numR != sqR){
            cout << "Not automorphic" << endl;
            break;
        }
        num /= 10;
        sq /= 10;
    }

    return 0;
}