// By Amortized method(dequeue costly only when s2 is empty)
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int a = s2.top();
            s2.pop();
            return a;
        }
        else{
            int a = s2.top();
            s2.pop();
            return a;
        }
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    // Instantiate the queue
    MyQueue* obj = new MyQueue();

    cout << "--- Starting Test Sequence ---\n";

    // 1. Push 1, 2, 3
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << "Pushed: 1, 2, 3\n";

    // 2. Pop 1, 2
    cout << "Popped: " << obj->pop() << " (Expected: 1)\n";
    cout << "Popped: " << obj->pop() << " (Expected: 2)\n";

    // 3. Push 4, 5
    obj->push(4);
    obj->push(5);
    cout << "Pushed: 4, 5\n";

    // 4. Peek and Pop remaining to verify correctness
    cout << "Current Peek: " << obj->peek() << " (Expected: 3)\n";
    cout << "Popped: " << obj->pop() << " (Expected: 3)\n";
    
    cout << "Current Peek: " << obj->peek() << " (Expected: 4)\n";
    cout << "Popped: " << obj->pop() << " (Expected: 4)\n";
    cout << "Popped: " << obj->pop() << " (Expected: 5)\n";

    // 5. Check if empty
    if (obj->empty()) {
        cout << "Queue is now empty! (Expected)\n";
    } else {
        cout << "Queue is not empty! (Error)\n";
    }

    // Clean up memory
    delete obj;
    return 0;
}