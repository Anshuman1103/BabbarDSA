#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int n){
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void BubbleRecursion(vector<int> &arr,int n){
    if(n == 1) return;

    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    BubbleRecursion(arr, n-1);
}

//Idea: Repeatedly swap adjacent elements if they are in the wrong order.

//Time Complexity: O(n²)

int main() {
    vector<int> arr = {5, 6 ,2, 3, 1, 8};
    int n = arr.size();

    cout << "Given array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

   // BubbleSort(arr, n);
   BubbleRecursion(arr, n);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}