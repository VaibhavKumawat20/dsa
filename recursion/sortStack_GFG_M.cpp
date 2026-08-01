#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st){
        if(st.empty()){
            return;
        }
        
        int temp = st.top();
        st.pop();
        
        solve(st);
        
        if(st.empty()){
            st.push(temp);    
        }
        else if(st.top() > temp){
            int num = st.top();
            st.pop();
            st.push(temp);
            st.push(num);
        }
        else{
            st.push(temp);
        }
    }
    
    void sortStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        
        solve(st);
        int n = st.top();
        st.pop();
        
        sortStack(st);
        
        st.push(n);
    }

int main(){
    stack<int> st;
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    sortStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}