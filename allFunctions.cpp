#include<bits/stdc++.h>
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

void reverseArray(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printFibonacci(int n){
    int a = 0;
    int b = 1;
    cout << a << " "<< b << " ";
    for (int i = 3; i < n+1; i++)
    {
        int c = a+b;
        cout << c << " " ;
        a = b;
        b = c;
    }
}

void bubbleSort(int arr, int n){

     for(int i = 1; i < n; i++){
        for(int j = 0; j <n-i; j++){ //unknown problem

            // if(arr[j] > arr[j+1]){

            //     swap(arr[j],arr[j+1]);
            // }
        }
    }
}

void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for (int i = 1; i < n; i++) {
      int temp = arr[i];
      int j = i - 1;
      for (; j >= 0; j--){
          if(temp < arr[j]){
              arr[j+1] = arr[j];
          }
          else{
              break;
          }
      }
      arr[j+1] = temp;
    }
}

vector<int> reverse(vector<int> v){
	int s = 0;
	int e = v.size()-1;
	while(s<e){
		swap(v[s++], v[e--]);
	}
	return v;
}


int main() {
    

}