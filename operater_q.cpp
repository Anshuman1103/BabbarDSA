#include<iostream>
using namespace std;

int main(){

    //Write a function that takes an unsigned integer and returns the number Of '1' bits it has (also as the Hamming weight).

    int n;
    int count = 0;
    cin >> n;

    while (n!=0)
    {
        if (n&1)
        {
            count++;
        }
        n = n>>1;
    }
    cout << count << endl;
}