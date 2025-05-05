#include<iostream>
using namespace std;

void printLove(int a, int n){
    if(a == n) return;
    cout << "I love Nancy" << endl;
    printLove(a+1, n);
}

int main(){
    int n;
    cin >> n;
    printLove(0,n);
    return 0;
}