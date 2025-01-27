#include<iostream>
using namespace std;
//Operator overloading 
class A{
    public:
    int a;
    int b;

    void operator+ (A &obj){ // operator ki funcionality hi change ke bi
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"output: "<< value2 - value1 << endl;
    }

    void operator() (){
        cout << "Bracket :"<< this->a << endl;
    }
};

int main(){
    A obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1 + obj2;

    obj1();
}