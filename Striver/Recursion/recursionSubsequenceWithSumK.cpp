#include<bits/stdc++.h>
using namespace std;

//Time complexity =     2^n     *    n
//                  recursion    for printing
//Space complexity = n(stack space );

void printSubsequenceWithSumK(vector<int> v, int i , vector<int> &sub, int sum, int k){
    if(i == v.size()){
        if(sum == k){
            if(sub.size() == 0){
                cout << "[]"<< endl;
                return;
            }
            for(auto &val: sub){
                cout<< val << " ";
            }
            cout << endl;
        }
        return;
    }
    
    sub.push_back(v[i]);
    sum += v[i];
    printSubsequenceWithSumK(v, i+1, sub, sum , k);

    sub.pop_back();
    sum -= v[i];
    printSubsequenceWithSumK(v, i+1, sub, sum , k);
}

//if want to print only one subsequence
// bool printSubsequenceWithSumK(vector<int> v, int i , vector<int> &sub, int sum, int k){
//     if(i == v.size()){
//         if(sum == k){
//             for(auto &val: sub){
//                 cout<< val << " ";
//             }
//             cout << endl;
//             return true;
//         }
//         return false;
//     }
    
//     sub.push_back(v[i]);
//     sum += v[i];
//     if(printSubsequenceWithSumK(v, i+1, sub, sum , k)){
//         return true;
//     }

//     sub.pop_back();
//     sum -= v[i];
//     if(printSubsequenceWithSumK(v, i+1, sub, sum , k)){
//         return true;
//     }
//     return false;
// }

//if want to print only number of subsequeces with sum k
// int printSubsequenceWithSumK(vector<int> v,int i , int sum, int k){
//     if(i == v.size()){
//         if(sum == k){
//             return 1;
//         }
//         return 0 ;
//     }
    
//     sum += v[i];
//     int l = printSubsequenceWithSumK(v, i+1, sum , k);

//     sum -= v[i];
//     int r = printSubsequenceWithSumK(v, i+1, sum , k);

//     return l + r;
// }

int main(){
    vector<int> v = {1,2, 1};
    vector<int> sub;
    int sum = 2;

    printSubsequenceWithSumK(v, 0, sub, 0,sum);
    return 0;

}