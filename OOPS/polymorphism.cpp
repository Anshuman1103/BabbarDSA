#include<iostream>
using namespace std;
//Function overloading
class A {
    public:
    void sayHello(){
        cout << "Hello Anshuman" << endl;
    }

    // int sayHello(){      this will not work
    //     cout << "Hello Anshuman" << endl;
    //     return 1;
    // }

    int sayHello(char name){
        cout << "Hello Anshuman" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout <<"Hello "<< name << endl;
    }
};

int main(){
    A obj;
    obj.sayHello("Anshuman");
    obj.sayHello();
}