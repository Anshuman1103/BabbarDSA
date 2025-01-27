#include<iostream>
#include<string.h>
using namespace std;

class hero{
    public:
    //Properties
    char *name;
    int health;
    char level;

    hero() {
        cout<<"Simple constructor called" << endl;
        name = new char[10];
    }

    
    void setHealth(int h){
        health = h;
    }
    void setLevel(char l){
        level = l;
    }

     int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void print(){
        cout <<"Name: "<< this->name<<endl;
        cout<<"Health: " << this->health<< endl;
        cout<<"Level: "<< this->level << endl;
    }

    ~hero(){
        cout << "Destructor called " << endl;
    }
};

int main(){

    hero a;
    hero *b = new hero();
    delete b;

    //static allocation = destructor called automatically
    //dynamic allocation = destructor called manually
    
}