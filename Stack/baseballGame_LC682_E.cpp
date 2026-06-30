#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

// // two stack solution(made by me)
//     int calPoints(vector<string>& operations) {
//         stack<int> record1;
//         stack<int> record2;

//         for(string i : operations){
//             if(i[0] == 'C'){
//                 if(!record2.empty()){
//                     record2.pop();
//                 }
//                 record1.pop();
//             }
//             else if(i[0] == 'D'){
//                 record2.push(record1.top());
//                 record1.push(2 * record1.top());
//             }
//             else if(i[0] == '+'){
//                 int x = record2.top();
//                 record2.push(record1.top());
//                 record1.push(record1.top() + x);
//             }
//             else{
//                 if(record1.empty()){
//                     int x = stoi(i);
//                     record1.push(x);
//                 }
//                 else{
//                     record2.push(record1.top());
//                     int x = stoi(i);
//                     record1.push(x);
//                 }
//             }
//         }
//         int ans = 0;
//         while(!record1.empty()){
//             ans += record1.top();
//             record1.pop();
//         }

//         return ans;
//     }

// single stack solution
    int calPoints(vector<string>& operations) {
        stack<int> record;

        for(string i : operations){
            if(i[0] == 'C'){
                record.pop();
            }
            else if(i[0] == 'D'){
                record.push(2 * record.top());
            }
            else if(i[0] == '+'){
                int first = record.top();
                record.pop();
                int second = record.top();
                record.push(first);
                record.push(first + second);
            }
            else{
                int x = stoi(i);
                record.push(x);
            }
        }
        int ans = 0;
        while(!record.empty()){
            ans += record.top();
            record.pop();
        }

        return ans;
    }

int main(){
    vector<string> operations = {"5","2","C","D","+"};

    cout << "Answer: " << calPoints(operations) << endl;

    return 0;
}