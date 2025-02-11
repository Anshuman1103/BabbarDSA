#include<bits/stdc++.h>
using namespace std;
//Hashing = pre storing and fecthing

void hashArray(int arr[], int n){
    int hash[n+1] = {0};
    int count = 0;
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    //print the hash result
    for(int i = 0; i < n; i++){
        if(hash[i] == 0) continue;
        cout << arr[i] <<" : "<< hash[arr[i]] << endl;
    }
    cout << endl;
}

// ASCII = 'a' - 97, 'A' - 65
void hashChar(string a){
    int hash[26] = {0};
    for(int i = 0; i < 26; i++){
        hash[a[i] - 'a']++; 
    }

    //printing the result
    for(int i = 0; i < 25; i++){
        if(hash[i] == 0) continue;
        cout << char(i + 'a') << " : "<< hash[i]<< endl;
    }
    cout << endl;
}

int main(){
    int arr[5] = {2, 5 , 3 ,2 ,1};
    hashArray(arr, 5);
    string str = "knightfury";
    hashChar(str);
}