#include<iostream>
using namespace std;

void printNumReverse(int a, int n){
    if(a > n) return;
    printNumReverse(a+1, n);
    cout << a << endl;
}

int main(){
    int n;
    cin >> n;
    printNumReverse(1,n);
    return 0;
}