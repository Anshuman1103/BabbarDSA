#include<iostream>
#include<set>
using namespace std;

//store duplicate elements at once only
//store them in ordered form
int main(){

    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(2);
    s.insert(4);

    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    for(int i:s){
        cout<<i<<endl;
    }

    cout<<"-5 is present or not "<<s.count(-5)<<endl;
    cout<<" 5 is present or not "<<s.count(5)<<endl;

    set<int>::iterator itr = s.find(5);
    for(auto it= itr; it!=s.end(); it++){
        cout<<*it<<" ";
    }cout<<endl;
}