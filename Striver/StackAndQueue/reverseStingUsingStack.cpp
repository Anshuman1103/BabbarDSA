#include <iostream>
#include <stack>
using namespace std;

string reverseUsingStack(string str){
    stack<char> st;

    for(char ch : str){
        st.push(ch);
    }

    string reversed = "";
    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

int main() {
    string input;
    getline(cin,input);

    cout << reverseUsingStack(input) << endl;

    return 0;
}