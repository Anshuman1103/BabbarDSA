#include<bits/stdc++.h>
using namespace std;

class stackUsingArray{
    int size;
    int top;
    int *arr;

    stackUsingArray(){
        top = -1;
        size = 100;
        arr = new int[size];
    }

    void push(int x){
        top++;
        arr[top] = x;
    }

    int pop(){
        if(top == -1) return;
        int x = arr[top];
        top--;
        return x;
    }

    int size(){
        return top+1;
    }
};

int main(){

}