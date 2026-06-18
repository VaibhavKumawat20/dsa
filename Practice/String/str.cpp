#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cout << "Enter string:";
    cin >> str;

    int count = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i] == 'a'){
            replace(str.begin(), str.end(), str[i], '1');
            count++;

        }
        else if(str[i] == 'e'){
            replace(str.begin(), str.end(), str[i], '2');
            count++;

        }
        else if(str[i] == 'i'){
            replace(str.begin(), str.end(), str[i], '3');
            count++;

        }
        else if(str[i] == 'o'){
            replace(str.begin(), str.end(), str[i], '4');
            count++;

        }
        else if(str[i] == 'u'){
            replace(str.begin(), str.end(), str[i], '5');
            count++;
        }
    }
    cout << count << endl;
    cout << str << endl;

    return 0;
}