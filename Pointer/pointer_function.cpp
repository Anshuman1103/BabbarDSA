#include<iostream>
using namespace std;

void print(int *p);
void update(int *p);

int main(){
    int value = 5;
    int *p = &value;
    cout << *p << endl;
    print(p);
    cout << *p << endl;
    update(p);
    cout << *p << endl;
    cout<<"In main function"<< endl;
    cout<<"Address:"<<p<<endl;
    cout<<"Value:"<< *p << endl;
    return 0;

}

void print(int *p){
    cout << p << endl;
    cout << *p << endl;
}

void update(int *p){
    cout <<"Inside"<<endl;
    p = p + 1;
    cout<<"Address:"<<p<<endl;
    *p = *p + 1;
    cout <<"Value:"<< *p << endl;

    cout << endl;
}