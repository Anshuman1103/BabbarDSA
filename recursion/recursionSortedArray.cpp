#include <iostream>
using namespace std;

bool isSortedArray(int *arr, int n)
{
    if (n == 0 || n == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    else
    {
        int remainingPart = isSortedArray(arr + 1, n - 1);
        return remainingPart;
    }
}

int main()
{
    int arr[] = {2, 5, 8, 9};
    int n = 4;

    if (isSortedArray(arr, n))
    {
        cout<<"The array is sorted"<<endl;
    }
    else cout<<"The array is not sorted"<<endl;
}