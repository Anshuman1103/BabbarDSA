#include<iostream>
#include<stack>
using namespace std;

//work on LIFO principle
int main(){

    stack<string> s;

    s.push("Nancy;");
    s.push("Khushi");
    s.push("Afifa");

    cout<<"Top "<<s.top()<<endl;
    cout<<"Empty or not "<<s.empty()<<endl;
    cout<<"Size "<<s.size()<<endl;

    s.pop();
    cout<<"Size "<<s.size()<<endl;
}