//completed
#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

int main(){
    int num;
    cout << "Enter num:";
    cin >> num;

    int sum = 0;
    int n = num;

    while(n){
        sum += factorial(n%10);
        n /= 10;
    }

    cout << (num == sum) << endl;

    return 0;
}