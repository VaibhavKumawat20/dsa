/*
pattern - 
*
**
***
****
*****

*/
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "";

    for(int i=0; i<5; i++){
        str.push_back('*');
        cout << str << endl;
    }

    return 0;
}