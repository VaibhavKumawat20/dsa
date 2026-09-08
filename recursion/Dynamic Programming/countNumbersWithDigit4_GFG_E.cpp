#include<iostream>
using namespace std;

int countNumberswith4(int n) {
        // code here
        int count = 0;
        
        for(int i=4; i<=n; i++){
            int j = i;
            while(j){
                if(j%10 == 4){
                    count++;
                    break;
                }
                j /= 10;
            }
        }
        
        return count;
    }

int main(){
    cout << countNumberswith4(14) << endl;

    return 0;
}