#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if(q1.empty() && q2.empty()){
            return -1;
        }
        else if(q1.empty()){
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            int a = q2.front();
            q2.pop();
            return a;
        }
        else{
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int a = q1.front();
            q1.pop();
            return a;
        }
    }

    int top() {
        if(q1.empty() && q2.empty()){
            return -1;
        }
        else if(q1.empty()){
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            int a = q2.front();
            q1.push(q2.front());
            q2.pop();
            return a;
        }
        else{
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int a = q1.front();
            q2.push(q1.front());
            q1.pop();
            return a;
        }
    }

    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    MyStack obj;

    obj.push(1);
    obj.push(2);
    obj.push(3);

    cout << "Top: " << obj.top() << endl;
    cout << "Pop: " << obj.pop() << endl;
    cout << "Top: " << obj.top() << endl;

    obj.push(4);

    cout << "Pop: " << obj.pop() << endl;
    cout << "Pop: " << obj.pop() << endl;
    cout << "Pop: " << obj.pop() << endl;

    if(obj.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}