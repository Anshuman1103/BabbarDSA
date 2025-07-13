#include<bits/stdc++.h>

using namespace std;

vector<int> leader(vector<int> &arr){
    vector<int> ans;
    int n = arr.size();
    int currMax = arr[n-1];
    ans.push_back(currMax);
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > currMax){
            currMax = arr[i];
            ans.push_back(currMax);
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int>ans = leader(arr);
    for(auto i : ans){
        cout << i << " ";
    }
}