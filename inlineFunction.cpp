#include<iostream>
using namespace std;

//Inline function
//must be can under one line , may or may not execute if above that

inline int getMax(int& a, int& b){
    return (a>b) ? a : b;
}

//Practionally getMax can replace by it's values inside it's function every time it's called
// It will enhance our system performance bcz  no function call

int main(){

    int a = 5, b = 3;
    int ans = getMax(a,b);

    cout << ans << endl;

    a = a + 1;
    b = b + 5;
    ans = getMax(a,b);
   cout << ans <<endl;
}