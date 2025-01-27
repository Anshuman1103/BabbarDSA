#include<iostream>
using namespace std;

int partision(int *arr, int s , int e){
    int count = 0;
    int pivot = arr[s];
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot) count++;
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < arr[pivotIndex]) i++;
        while(arr[j] > arr[pivotIndex]) j--;
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
        }
    }
    return pivotIndex;
}

void QuickSort(int *arr, int s, int e){
    if(s >= e) return;
    int p = partision(arr, s, e);
    QuickSort(arr, s, p-1);
    QuickSort(arr, p+1, e);
}

void printArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {3, 5, 1, 4 ,2 };
    QuickSort(arr, 0, 4 );
    printArray(arr, 5);
}