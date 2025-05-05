#include<bits/stdc++.h>
using namespace std;

//Time complexity = 2^n     *    n
//                  recursion    for printing
//Space complexity = n(stack space );

void printSubsequence(vector<int> v, int i , vector<int> &sub){

    if(i == v.size()){
        if(sub.size() == 0){
            cout << "[]"<< endl;
            return;
        } 
        for(auto &val: sub){
            cout<< val << " ";
        }
        cout << endl;
        return;
    }

    sub.push_back(v[i]);
    printSubsequence(v, i+1, sub);
    sub.pop_back();
    printSubsequence(v, i+1, sub);

}

int main(){
    vector<int> v = {3,1, 2 };
    vector<int> sub;
    printSubsequence(v, 0, sub);
    return 0;

}