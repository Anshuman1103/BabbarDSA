#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    vector<int> v;

    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);
    
    cout<<"Finding 6: "<<binary_search(v.begin(), v.end(), 6)<<endl;

    cout<<"Lower bound: "<<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;
    cout<<"Upper bound: "<<upper_bound(v.begin(), v.end(), 4)-v.begin()<<endl;

    int a = 2;
    int b = 5;

    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a : "<<a<<" b : "<<b<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout<<"string -> "<<abcd<<endl;

    rotate(v.begin(), v.begin()+1, v.end());
    cout<<"After rotation"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
}