#include<iostream>
using namespace std;

void reverse(int arr[], int l, int r){
    if(l >= r) return ;
    swap(arr[l], arr[r]);
    reverse(arr, l+1, r-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout << "The reversed array is : ";
    reverse(arr,0, 4);
    for(int val: arr){
        cout << val << " " ;
    }
    return 0;
}