#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v1(5,1); //v1 vector is created having size 5 and initialise all the element with 1
    for(int i:v1){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v2(v1); // v2 copies all the element from v1
    for(int i:v2){
        cout<<i<<" ";
    }cout<<endl;


    vector<int> v;
    cout<<"Capacity "<< v.capacity()<<endl;
    
    v.push_back(1);
    cout<<"Capacity "<< v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity "<< v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity "<< v.capacity()<<endl;
    cout<<"Size "<< v.size()<<endl;
   
    cout<<"Element at 2 index "<<v.at(2)<<endl;

    cout<<"Fornt "<< v.front()<<endl;
    cout<<"Back "<< v.back()<<endl;

    cout<<"Before pop "<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();
    
    cout<<"After pop "<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;
    
    cout<<"Before Clear "<<endl;
    v.clear();
    cout<<"After clear "<<endl;

    cout<<"Capacity "<< v.capacity()<<endl;
    cout<<"Size "<< v.size()<<endl;

}