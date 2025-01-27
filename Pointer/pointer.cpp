#include<iostream>
using namespace std;


int main(){
    double n;
    double *ptr = &n;

    cin >>  n;

    // &n = ptr = address
    cout <<" The address is " << &n <<" "<< ptr << endl;

    // *ptr = n = value 
    cout <<" The value is " << n <<" "<< *ptr << endl;

    cout <<"The size is "<< sizeof(ptr)<< endl;
}