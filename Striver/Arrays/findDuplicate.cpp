#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> arr){
    map<int,int> mpp;
    for(int i = 0; i < arr.size(); i++){
        if(mpp[arr[i]] == 1) return arr[i];
        else mpp[arr[i]]++;
    }
    return -1;
}

int main() {
    vector<int> arr = {1,4,7,6,5,4};
    cout << findDuplicate(arr);
}