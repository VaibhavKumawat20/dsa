#include<iostream>
using namespace std;

int minOperation(int n) {
        int count = 0;
        while(n){
            if(n%2){
                n--;
            }
            else{
                n /= 2;
            }
            
            count++;
        }
        
        return count;
    }

int main(){
    cout << minOperation(11) << endl;

    return 0;
}