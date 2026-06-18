#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1 = "hack", str2 = "slash";

    string res = str1+str2;

    cout << res << endl;

    // cout << res.at(4);

    res.pop_back();
    cout << res << endl;

    // res.push_back("h1");
    // cout << res << endl;

    cout << res.length() << endl;

    string temp = str1;
    cout << temp << endl;
    temp.append(str2);
    cout << temp << endl;
    temp.insert(4, "into");
    cout << temp << endl;
    temp.erase(4, 4);
    cout << temp << endl;

    cout << temp.find("k") << endl;
    cout << temp.rfind("l") << endl;

    return 0;
}