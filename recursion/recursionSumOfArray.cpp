#include <iostream>
using namespace std;

int sumArray(int *arr, int n){
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    else{
        int sum = arr[0] + sumArray(arr+1,n -1);
        return sum;
    }

}

int main()
{
    int arr[] = {2, 5, 8, 9};
    int n = 4;

    cout <<"The sum "<<sumArray(arr, n);
}