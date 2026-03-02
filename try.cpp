#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low , int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left++]);
        }
        else{
            temp.push_back(nums[])
        }
    }
}

void mergesort(vector<int> &nums, int low, int high){
    if(low >=high) return; 
    int mid = low + (high - low)/2;
    mergesort(nums, low, mid);
    mergesort(nums, mid+1, high);
    merge(nums,low ,mid, high);
}

int main() {
   
    return 0;
}