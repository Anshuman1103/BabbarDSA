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


// void reverseArray(int arr[], int n){  // using another array
//     int reverse[n] = {0};
//     for (int i = 0, k = n-1; i < n, k >= 0; i++, k--)
//     {
//         reverse[k] = arr[i];
//     }
//     printArray(reverse, n);
// }

void reverseArray(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    
    int arr[10] = {0};
    printArray(arr, 10 );

    int arr1[10] = {2};
    printArray(arr1, 10);

    inputArray(arr, 10);

    reverseArray(arr, 10);
    printArray(arr, 10);
}