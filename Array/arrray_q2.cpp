#include<iostream>
using namespace std;

/*input an array with numbers 0, 1 and bring all the ones in right and all the zero at left*/

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

void sort01inArray(int arr[], int n){
    int start = 0, end = n-1;
    while ( start < end )
    {
        while (arr[start] == 0 && start < end)
        {
            start++;
        }
        while (arr[end] == 1 && start < end)
        {
            end--;
        }
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    inputArray(arr, n);
    sort01inArray(arr, n);
    printArray(arr, n);

}