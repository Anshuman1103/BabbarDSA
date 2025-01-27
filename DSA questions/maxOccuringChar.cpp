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

char maxOccurence(string s){
    int arr[26] = {0};
    int maxIndex = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int num = 0;
        if(ch >= 'a' && ch <= 'z'){
            num = ch - 'a';
        }
        else num = ch - 'A';
        arr[num]++;
        if ( arr[num] > arr[maxIndex])
        {
            maxIndex = num;
        }
        
    }
    return  'a' + maxIndex;
    
}

int main(){
    string s;
    cin>>s;
    cout<<maxOccurence(s)<<endl;
    return 0;
}