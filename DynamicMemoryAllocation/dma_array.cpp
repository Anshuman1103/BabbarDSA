#include<iostream>
using namespace std;

int getSum( int *arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(){

    int n;
    cin >> n;
    
    int* arr = new int[n]; // variable size array
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int  i = 0; i < n; i++)
    {
        cout << arr[i]<< endl;
    }

    cout<<endl<<endl;

    int sum = getSum(arr, n);

    cout <<"The sum is: "<< sum << endl;
    

    // to free the m/m

    // delete i;   -> for single element

    // delete []arr  -> for array
}