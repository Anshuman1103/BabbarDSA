#include<iostream>
using namespace std;


int main(){
    int i = 1;
    
    int *p = 0; 
    p = &i;
    // same as *p = &i
    cout << p << endl;
    cout << *p <<endl;

    cout<<"second phase"<<endl;

    (*p)++;
    cout<<"a -> "<<i<<endl;

    //copying a pointer
    int *q = p;
    cout<<"*q -> "<<*q<<endl;
    cout<<"*p -> "<<*p<<endl;

    //important concept
    int a = 5;
    int *t = &a;
    cout<<"Before t"<< t <<endl;
    *t = *t + 1; // (*t)++
    cout<<"Before t"<< t <<endl;
    t = t + 1; // here the t will shift a fixed bit forward depending on the datatype it
    cout<<"After t"<< t << endl;

    

}