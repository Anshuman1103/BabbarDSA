#include<iostream>
#include<list>
using namespace std;

//implemented with the help of deque
int main(){
    
    list<int> l;

    l.push_front(1);
    l.push_back(2);
    // list have pop operation also

    list<int> m(l);
    for(int i:m){
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> n(5, 100);
    for(int i:n){
        cout<<i<<" ";
    }cout<<endl;
    
    l.erase(l.begin());//jisko point karega wo delete ho gayega
    cout<<"After erase"<<endl;
    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"size of list "<<l.size()<<endl;
}