#include<iostream>
using namespace std;

void printNumber(int n){
   if(n == 0){
    return ;
   }
   //Tail recursion
    // cout << n << " ";
    // printNumber(n-1);

    //Head recursion
    printNumber(n-1);
    cout << n << " ";
    
}

int main(){
    int n;
    cin >> n;
    printNumber(n);

}