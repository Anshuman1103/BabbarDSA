#include<iostream>
using namespace std;

void say_Digit(int n, string arr[]){
   //base  case
   if(n == 0) return;

   //processing
   int digit = n % 10;
   n = n / 10;
    say_Digit(n, arr);
   cout << arr[digit]<< endl;

}

int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin >> n;
    say_Digit(n,arr);

}