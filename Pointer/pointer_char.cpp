#include<iostream>
using namespace std;


int main(){
    int arr[] = {2,7,9};
    char ch[6] = "abcde";

    cout << ch << endl;

    char *c = &ch[0];
    // will print the entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;
    // tab tak chalega jab tak null character nahi mil jata
    cout << p <<endl;

    // char *c = "abcde" -> risky don't do ita

}