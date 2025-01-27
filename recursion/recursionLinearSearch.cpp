#include <iostream>
using namespace std;

bool linearSearch(int *arr, int n , int k){
    if(n == 0) return false;
    if(arr[0] == k ) return true;

    else{
        int remain = linearSearch(arr + 1,n-1, k);
        return remain;
    }
}

int main()
{
    int arr[] = {7, 2, 5, 8, 9};
    int n = 5;
    int k = 5;

    if (linearSearch(arr, n, k))
    {
        cout<<"present"<<endl;
    }
    else    cout << "Absent" << endl;
}