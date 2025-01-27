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

void reverseString(char str[], int n){
    int s = 0;
    int e = n-1;
    while (s<e)
    {
        swap(str[s++], str[e--]);
    }
    cout<<"Reverse : "<<str<<endl;
}

int palindromeString(char str[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(str[s] != str[e]){
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
    cout<<str<<endl;
    int len = stringLength(str);
    cout<<"Length:"<<stringLength(str)<<endl;
    reverseString(str, len);
    if(palindromeString(str, len)){
        cout<<str<<" is palindrome."<<endl;
    }
    else cout <<str<< " is not palindrome"<<endl;

    //length strlen(str)
    //copy string strcpy(destination, source)
    //compare strcmp(str1, str2)
    return 0;
}