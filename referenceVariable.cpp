#include<iostream>
using namespace std;

void update(int& n ){ // call by reference 
    n++;
}

int& func(int a){ // bad practice 
    int num = a;
    int& ans = num;
    return ans;
}

int* func1(int a){// bad practice due to local variables inside function block
    int* ptr = &a;
    return ptr;
}

int main(){

    int i = 5;
    int& j = i;

    cout << i << endl;
    cout << j << endl;
    i++;
    cout<< i << endl;
    cout << j << endl;
    j++;
    cout << i << endl;
    cout << j << endl;

    update(i);
    cout << i << endl; 

    func(i);
    cout << "Fine" << endl;
}