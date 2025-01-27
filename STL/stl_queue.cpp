#include<iostream>
#include<queue>
using namespace std;

//work on FIFO principle
int main(){

    queue<string> q;

    q.push("Nancy");
    q.push("Khushi");
    q.push("Afifa");
    
    cout<<"Front "<<q.front()<<endl;
    q.pop();
    cout<<"Front "<<q.front()<<endl;

    cout<<"Size "<<q.size()<<endl;

}