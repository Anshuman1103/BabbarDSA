#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    private:
    stack<int> st1;
    stack<int> st2;

    public:
    void push(int d){
        if(st1.empty()){
            st1.push(d);
            return;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(d);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    void pop(){
        if(st1.empty()){
            cout << "Empty" << endl;
            return;
        }
        st1.pop();
    }

    void top(){
        if(st1.empty()){
            cout<<"Empty" << endl;
            return;
        }
        cout << st1.top() << endl;
    }

    //There is a second approach that can reduce the time consumed by the push operation in order to complete

    // void push(int d){
    //     st1.push(d);
    // }

    // void pop(){
    //     if(!st2.empty()){
    //         st2.pop();
    //         return;
    //     }
    //     while(!st1.empty()){
    //         st2.push(st1.top());
    //         st1.pop();
    //     }
    //     st2.pop();
    // }

    // void top(){
    //     if(!st2.empty()){
    //         st2.top();
    //         return;
    //     }
    //     while(!st1.empty()){
    //         st2.push(st1.top());
    //         st1.pop();
    //     }
    //     st2.top();
    // }

};

int main() {
    QueueUsingStack q;
    q.push(5);
    q.push(6);
    q.top();
    q.pop();
    q.top();
    q.pop();
    q.pop();
    q.top();
    return 0;
}