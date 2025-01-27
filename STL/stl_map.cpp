#include<iostream>
#include<map>
using namespace std;

//unique keys points to a value
int main(){
    map<int,string> m;
    
    m[1] = "Nancy";
    m[3] = "Afifa";
    m[2] = "Khushi";

    m.insert({5, "Tsukasha"});

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    cout<<"Is 1 present: "<<m.count(1)<<endl;

    cout<<"After erase"<<endl;

    m.erase(2);

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    auto it = m.find(5);

    for(auto i = it; i!= m.end(); i++){
        cout <<  (*i).second <<endl;
    }

}