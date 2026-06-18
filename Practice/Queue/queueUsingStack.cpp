// By making Enqueue costly
#include<iostream>
#include<stack>
using namespace std;

class QueueUsingStack{
    public:

    stack<int> s1, s2;

    void Enqueue(int value){    
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(value);
        cout << value << " is enqueued." << endl;
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }

    void Dequeue(){
        cout << "Dequeued." << endl;
        s1.pop();
    }

    void display(){
        stack<int> temp = s1;
        cout << "Queue: ";
        while(!temp.empty()){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "\n" << endl;
    }

    void peek(){
        cout << "Front of queue is " << s1.top() << endl;
    }
};

int main(){
    QueueUsingStack q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.peek();
    q.display();

    q.Dequeue();
    q.peek();
    q.display();

    return 0;
}