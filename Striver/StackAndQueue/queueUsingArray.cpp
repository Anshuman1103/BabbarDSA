#include<bits/stdc++.h>
using namespace std;

class queueUsingArray{

    int maxSize = 5, currSize = 0, start = -1, end = -1;
    int q[5];

    public:

    void push(int x){
        if(currSize == maxSize){
            cout << "Can't push" << endl;
            return;
        }
        if(currSize == 0){
            start = 0;
            end = 0;
        } else{
            end = (end + 1) % maxSize;
        }
        q[end] = x;
        currSize++;
    }

    int pop(){
        if(currSize == 0){
            cout << "Can't pop" << endl;
            return -1;
        }
        int ele = q[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return ele;
    }

    int top(){
        if(currSize == 0){
            cout << "Empty" << endl;
            return -1;
        }
        return q[start];
    }

    int Size(){
        return currSize;
    }
};

int main(){
    queueUsingArray q;
    q.push(5);
    q.push(6);
    cout << q.pop() << endl;
    q.push(8);
    cout << q.pop() << endl;
    cout << q.Size() << endl;
    cout << q.top() << endl;
}