#include<iostream>
using namespace std;

/*input n , print nth term in fibonacci series */

void printFibonacci(int n){
    int a = 0;
    int b = 1;
    int c ;
    cout << a << " "<< b << " ";
    for (int i = 3; i < n+1; i++)
    {
        c = a + b;
        cout << c << " " ;
        a = b;
        b = c;
    }
    cout << endl <<"The nth term is "<< c << endl;
}

int main(){
    
    int n;
    cin >> n;
    printFibonacci(n);

}