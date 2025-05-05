#include<iostream>
using namespace std;

// Time complexity = 2^n (exponential in nature)

int fibonacci(int n){
    if(n <= 1) return n;
    int last = fibonacci(n-1);
    int slast = fibonacci(n-2);
    return last + slast;
}

int main(){
   int n;
   cin >> n;
   cout << "The nth term in fibonacci is : "<< fibonacci(n)<< endl;
}