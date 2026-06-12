// remaining
#include<iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter n:";
    cin >> n;
    int temp = n;
    int sum = 0;

    while(temp/10){
        while(temp){
            sum += (n%10);
            temp /= 10;
        }
        temp = sum;
    }
}