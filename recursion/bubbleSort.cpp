#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n){
    //already sorted
    if(n == 0 || n == 1) return;

    //largest element ko last me pahucha dega
    for(int i = 0; i < n; i ++){
        if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, n-1);
}

void printArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5, 3, 8, 1, 6};
    bubbleSort(arr, 5);
    printArray(arr,5);
} 