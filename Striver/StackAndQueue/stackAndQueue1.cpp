#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<int> st;
    queue<int> q;

    st.push(10);
    cout << "Stack top: " << st.top() << endl; // 10
    cout << "Stack size: " << st.size() << endl;
    cout << "Is stack empty? " << st.empty() << endl; // 0 (false)
    st.pop();

    q.push(100);
    q.push(200);
    cout << "Queue front: " << q.front() << endl; // 100
    cout << "Queue back: " << q.back() << endl;   // 200
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue empty: " << q.empty() << endl;
    q.pop(); // removes 100

    return 0;
}
