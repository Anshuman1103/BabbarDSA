#include<iostream>
using namespace std;

bool palindrome(string str,int i){
    int n = str.length();
    if(i >= n/2) return true;
    if(str[i] != str[n-1-i]) return false;
    return palindrome(str, i+1);
}

int main(){
    string str = "";
    getline(cin,str);
    int n = str.length();

    cout << palindrome(str, 0) << endl;
    return 0;
}