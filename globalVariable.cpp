#include<iostream>
using namespace std;

/*Global variables*/

int a = 5; // bad practice bcz can be changed by anyone

void func(){
    cout <<"a in func: "<< a <<endl;
}

int main(){

   cout <<"a in main: "<<a <<endl;
    func();
}