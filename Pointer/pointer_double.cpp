#include<iostream>
using namespace std;

void update(int **p){ //pass by value

    //p = p + 1; // it will cause no change to the value 

    //*p = *p + 1; // this will update the value stored at p

    **p = **p + 1;// this will update the value of i

}


int main(){

    int i = 5;
    int *p = &i;
    int **p1 = &p;

    cout<<"The value is "<< i <<" "<< *p << " "<< **p1 <<endl;

    cout <<"The address of i"<<&i<<" "<<p<<" "<<*p1<<endl;

    cout<<endl<<endl;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p1<<endl;
    update(p1);
    cout<<"After function:"<<endl;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p1<<endl;

}