#include<iostream>
using namespace std;

void inputArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;
}
/*Original array: [1, 2, 3, 4, 5, 6]
Rotated array: [4, 5, 6, 1, 2, 3]
Pivot element: 1 (the smallest element)*/

int binarySearchPivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while (s<e)
    {
        if(arr[mid] >= arr[0]) s = mid + 1;
        else e = mid;
        mid = s + (e-s)/2;
    }
    return s;
    
}

int main() {

    int arr[] = {3,8, 10, 17, 1};
    cout << binarySearchPivot(arr, 5) << endl;
}