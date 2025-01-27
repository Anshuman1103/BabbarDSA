#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m,int arr3[]){

    int i = 0,j = 0, k = 0;
    while (i<n && j<m){

       if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
       }
       else{
            arr3[k++] = arr2[j++];
       }
       
    }

    while (i<n){
        arr3[k++] = arr1[i++];
    }
    
    while (j<m){
        arr3[k++] = arr2[j++];
    }
    
}

void printArray(int arr[], int n){
    for (int  i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

   int arr1[] = {2,5,6, 7 ,9};
   int arr2[] = {1,3,4,7};

   int n = 5;
   int m = 4;

   int arr3[9] ={0};
   merge(arr1, arr2, n, m, arr3);
    
    printArray(arr3,9);
}