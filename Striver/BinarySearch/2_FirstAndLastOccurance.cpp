#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3 ,5, 5 ,5 ,5 ,5 , 8};
    int target = 5;
    auto first = lower_bound(v.begin(), v.end(), target);
    auto last = upper_bound(v.begin(), v.end(), target);
    int low = first - v.begin();
    int high = last - v.begin() - 1;

    if((v[low] == v.size()) || v[low] != target){
        cout << "Element is not present " << endl;
        return;
    } 

    cout << "First : " << low << endl;
    cout <<"Last : " << high << endl;
    cout <<"Number of occurance :" << high - low + 1 << endl ;
}