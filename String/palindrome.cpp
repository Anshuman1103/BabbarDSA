#include<iostream>
using namespace std;

int stringLength(char str[]){
    int count = 0;
    for (int  i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'b'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int palindromeString(char str[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(toLowerCase(str[s]) != toLowerCase(str[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}


int main(){
    char str[20];
    cin>>str;
    int len = stringLength(str);
    cout<<"Length:"<<stringLength(str)<<endl;
    if(palindromeString(str, len)){
        cout<<str<<" is palindrome."<<endl;
    }
    else cout <<str<< " is not palindrome"<<endl;
    return 0;
}