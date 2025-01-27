#include<iostream>
using namespace std;

void print(int arr[], int n){
    cout << sizeof(arr) << endl;
    //function me array , as a pointer pass hota hai
}

int main(){
    int arr[] = {2,7,9};
    cout << "Address of array: "<< arr<< " " << &arr[0] << endl;

    cout <<"now " << *arr<<endl;
    cout <<"4th "<< *arr +1 <<endl;
    cout <<"5th "<< *(arr + 1) << endl;

    int i = 2;
    cout <<"6th "<< i[arr]<< endl;
    cout <<"7th "<< 2[arr]<< endl;

    int *ptr = &arr[0];
    cout << sizeof(ptr)<<endl;
    cout << sizeof(*ptr)<<endl;
    cout << sizeof(&ptr)<<endl;

    cout<<"about array: "<< sizeof(arr)<<endl;
    cout << sizeof(*arr)<<endl;
    cout << sizeof(&arr)<<endl;

    // arr = arr + 1 -> this will give error
    

}