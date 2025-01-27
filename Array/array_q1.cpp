#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inputArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;
}

void swapAlternate(int arr[], int n){
    for (int i = 0, j = 1; i < n-1, j < n; i+=2, j+=2)
    {
        swap(arr[i], arr[j]);
    }
    
}

int main() {
    
    int arr[5];
    int arr1[6];

    inputArray(arr, 5);
    inputArray(arr1, 6);

    swapAlternate(arr, 5);
    swapAlternate(arr1, 6);

    printArray(arr,5);
    printArray(arr1,6);

    
}