#include<iostream>
using namespace std;

/*You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.*/

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

int main(){

    int n,K;
    cin >> n>> K;
    int arr[n];
    bool flag = 1;

    inputArray(arr, n);

    for (int i = 0; i < n; i++) {
         for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == K){
                   cout << "Answer is: " <<arr[i]<<","<<arr[j]<<","<<arr[k] << endl;
                   flag = 0;
                }
             }
         }
    }
    if (flag)
    {
        cout << "No match found"<< endl;
    }
    

}

