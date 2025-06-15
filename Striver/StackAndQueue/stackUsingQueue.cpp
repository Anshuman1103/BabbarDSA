#include <bits/stdc++.h>
using namespace std;

class stackUsingQueue{
    private:
    queue<int> q;
    
    public:
    void push(int d){
        q.push(d);
        int s = q.size();
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(q.empty()){
            cout << "Empty" << endl;
            return;
        }
        q.pop();
    }

    void top(){
        if(q.empty()){
            cout <<"Empty" << endl;
            return;
        }
        cout << q.front() << endl;
    }

};

int main() {
    stackUsingQueue st;
    st.push(5);
    st.push(7);
    st.push(8);
    st.top();
    st.pop();
    st.top();

    return 0;
}