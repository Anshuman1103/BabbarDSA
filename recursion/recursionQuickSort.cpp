#include<iostream>
using namespace std;


int Partision(int *arr, int s, int e){
    int count = 0;
    int pivot  = arr[s];
    
    for(int i = s; i < e; i++){
        if(arr[i] <= pivot) count++;
    }
    
    //place pivot at right position
    int pivotIndex = s + count;

    swap(arr[s], arr[pivotIndex]);

    //Handling left and right pat 
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] < arr[pivotIndex]) i++;

        while( arr[j] > arr[pivotIndex]) j--;

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
        }

    }
    return pivotIndex;
}

void QuickSort(int *arr, int s, int e){
    if( s >= e ) return ;

    int p = Partision( arr , s , e);

    QuickSort(arr, s , p-1);
    QuickSort(arr, p + 1 , e);
}

void printArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2, 9, 4, 7 , 1};
    QuickSort(arr, 0, 4);
    printArray(arr, 5);
}