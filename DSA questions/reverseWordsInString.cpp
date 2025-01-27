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
    

int main(){
    
    return 0;
}