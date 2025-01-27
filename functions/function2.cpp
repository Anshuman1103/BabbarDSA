#include<iostream>
using namespace std;


int fact(int n){
    int fact = 1;
    for (int i = 1; i <= n ; i++){
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r){
    int numerator = fact(n);
    int denominator = fact(r)*fact(n-r);
    return numerator/denominator;
}

int main() {
    int n,r;
    cin >> n >> r ;
    cout << nCr(n,r)<< endl;
    return 0;
}