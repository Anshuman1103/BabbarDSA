#include<bits/stdc++.h>
using namespace std;

void hashmap(int arr[], int n){
    map<int, int> mpp;
    //unordered_map<int, int> mpp; // this will store data in unordered way

    //storing in the map
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    //printing the mappedd data
    for(auto it: mpp){
        cout << it.first <<" -> " << it.second<< endl;
    }
}

int main(){
    int arr[5] = {2, 3, 5 ,2 ,1};
    hashmap(arr, 5);

}