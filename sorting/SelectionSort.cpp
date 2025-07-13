#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
    int minIndex = i;
    for(int j = i+1; j < n; j++){
        if(arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }
    swap(arr[i], arr[minIndex]);
    }
}

void selectionRecur(vector<int> &arr, int start,int n){
   if(start >= n-1){
        return;
   }
   int minIndex = start;
   for(int i = start; i < n; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
   }
   swap(arr[start], arr[minIndex]);
   selectionRecur(arr, start+1, n);
}

//Idea: Find the minimum element and place it at the beginning.

//Time Complexity: O(n²)

int main() {
    vector<int> arr = {5, 6 ,2, 3, 1, 8};
    int n = arr.size();

    cout << "Given array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    //selectionSort(arr, n);
    selectionRecur(arr, 0, n);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}