#include<iostream>
using namespace std;

int findMin(int n) {
        // code here
        int sum = 0;
        int coins = 0;
        
        while(sum != n){
            if(n-sum > 9){
                sum += 10;
                coins++;
            }
            else if(n-sum > 4){
                sum += 5;
                coins++;
            }
            else if(n-sum > 1){
                sum += 2;
                coins++;
            }
            else{
                sum += 1;
                coins++;
            }
        }
        
        return coins;
    }

int main(){
    cout << findMin(39) << endl;

    return 0;
}