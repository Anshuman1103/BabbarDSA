#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr,int k){
    int n = arr.size();
    k = k % n;
    //For left rotation
    // reverse(arr.begin(), arr.begin() + k);
    // reverse(arr.begin() + k, arr.end());
    // reverse(arr.begin(), arr.end());
    
    //For right rotation
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3 , 4 , 5};
    int k = 2;
    rotate(arr, k);
    for(auto i : arr){
        cout << i << " ";
    }
    return 0;
}