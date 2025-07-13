#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int low , int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid &&  right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(nums[left++]);
    }

    while(right <= high){
        temp.push_back(nums[right++]);
    }

    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low , int high){
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Given array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}