#include<iostream>
using namespace std;

/*input an array with numbers 0, 1, 2 and bring all the zeroes at left, one at mid and all the two at right*/

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
//Dutch flag algorithm
void sort012inArray(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
        else mid++;
    }
    
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    inputArray(arr, n);
    sort012inArray(arr, n);
    printArray(arr, n);

}