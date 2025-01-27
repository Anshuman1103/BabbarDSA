#include<iostream>
using namespace std;

bool palindrome(string& str, int i, int j){
    if(i > j) return true;
    if(str[i++] != str[j--]) return false;
    else return palindrome(str, i , j);
}

int main(){
    string str = "afifa";   
    cout << palindrome(str, 0, str.length() - 1) << endl;

} 