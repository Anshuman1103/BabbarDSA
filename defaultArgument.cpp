#include<iostream>
using namespace std;

// It's make an arguement optional
// Alway start making default argument form right hand side while defining arguements

void printArray(int arr[], int n, int start = 0){
    for (int  i = start; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

   int arr[] = {5, 3 , 8 , 9 , 1};
   printArray(arr, 5);
   cout<<endl<<endl;
   printArray(arr, 5, 2);

}