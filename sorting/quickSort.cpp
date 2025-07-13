#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int sort(vector<int> &arr, int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int> &arr, int low , int high){
    if(low > high) return ;
    int partition = sort(arr, low, high);
    quickSort(arr, low, partition-1);
    quickSort(arr, partition+1, high);
}

int main() {
    // Your code here
    vector<int> arr = {1, 8, 3, 5, 2, 7};
    int n = arr.size();

    cout << "Given array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}