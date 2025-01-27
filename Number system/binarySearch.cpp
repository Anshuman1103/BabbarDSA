#include<iostream>
using namespace std;

void inputArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;
}
/*Binary search can work with both increasing and decreasing order but we need to make few changes in code*/

// This code is desingned to work on increasing order

// time complexity = O(log n)

int binarySearch(int arr[], int n, int k){
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end){
        mid = start +(end - start)/2;  // sometime if int's value might escape the range of 2^31 -1 

        if (arr[mid] == k)  return mid;

        else if(arr[mid] < k) start = mid + 1;

        else end = mid - 1;
    }
    return -1;
}

int main() {

    int n,k;
    cin >> n >> k;
    int arr[n];
    cout << "Enter the array: "<< endl;
    inputArray(arr, n);
    cout << "The answer is: " << binarySearch(arr, n, k)<< endl;
}