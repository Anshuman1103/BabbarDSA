#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s , int e, int k){
    if(s>e) return false;

    int mid = s +(e-s)/2;

    if(arr[mid] == k) return true;

    if(arr[mid] > k) return binarySearch(arr, s, mid-1, k);
    
    else return binarySearch(arr, mid+1, e, k);
}

int main()
{
    int arr[] = {2,3, 5, 8, 9};
    int n = 5;
    int k = 10;

    if (binarySearch(arr,0, n-1, k))
    {
        cout<<"present"<<endl;
    }
    else    cout << "Absent" << endl;
}