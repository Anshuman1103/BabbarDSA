#include<bits/stdc++.h>

using namespace std;

void sorting(vector<int> &arr){
    int n = arr.size();
    int low = 0, mid = 0 , high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;  
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}


int main() {
    vector<int> arr = {2,0,2,1,1,0};
    sorting(arr);
    for(auto i : arr){
        cout << i << " ";
    }
}