#include<iostream>
#include<stack>
using namespace std;

stack<int> insertAtBottom(stack<int> &st, int x) {
        if(st.empty()){
            st.push(x);
            return st;
        }
        int n = st.top();
        st.pop();
        st = insertAtBottom(st, x);
        st.push(n);
        return st;
    }

int main(){
    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(1);

    st = insertAtBottom(st, 4);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}