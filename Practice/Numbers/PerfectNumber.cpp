// completed
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter n:";
    cin >> n;

    if(n == 1){
        cout << false << endl;
        return 0;
    }

    int sum = 1;
    int num = n;

    for(int i=2; i*i<=num; i++){
        if(n%i == 0){
            sum += i;
            if(i != n/i){
                sum += n/i;
            }
        }
    }
    
    cout << (sum == n) << endl;

    return 0;
}