#include<iostream>
#include<stack>
using namespace std;

int mystack[50]; int top = -1;

void push(){
    if(top == 49)
        cout << "Stack overflow" << endl;
    else{
        top++;
        cout << "Enter new element:";
        cin >> mystack[top];
    }
}
void pop(){
    if(top == -1)
        cout << "Stack underflow" << endl;
    else{
        cout << mystack[top] << " is deleted.\n" << endl;
        top--;
    }
}
void peek(){
    if(top == -1)
        cout << "Stack underflow" << endl;
    else{
        cout << "\n" << mystack[top] << " is on the top.\n" << endl;
    }
}
void display(){
    int i;
    if(top == -1)
        cout << "Stack underflow" << endl;
    else{
        cout << endl;
        for(i=top; i>=0; i--){
            cout << mystack[i] << " ";
        }
        cout << "\n" << endl;
    }
}


int main(){
    // push();
    // push();
    // push();
    // push();

    // display();

    // pop();
    // pop();

    // display();

    // peek();

    int ch;
    while(1){
        cout << "1-push \n 2-pop \n 3-peek \n 4-display \n 5-Exit \n";
        cin >> ch;

        switch(ch){
            case 1 : push();
            break;

            case 2 : pop();
            break;

            case 3 : peek();
            break;

            case 4 : display();
            break;

            case 5 : exit(0);
            break;
        }
    }

    return 0;
}