#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    while (a != b)
    {
        if(a > b) a = a - b;
        else b = b - a;

    }
    return a;
}

// lcm(a,b) * gcd(a,b) = a*b

int main(){
    int a, b;
    cout<<"Enter two numbers:"<<endl;
    cin>>a>>b;
    cout << "The GCD is "<<gcd(a,b)<<endl;
}