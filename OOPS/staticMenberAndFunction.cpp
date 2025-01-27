#include<iostream>
#include<string.h>
using namespace std;

class hero{
    public:
    //Properties
    char *name;
    int health;
    char level;

    static int  timeToComplete;

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

    static int random(){//can access only static data member
        cout <<timeToComplete << endl;
    }
};

int hero::timeToComplete = 10; //belongs to the class itself means if changed by any instance this it will change for all instances

int main(){

    cout << hero::timeToComplete << endl;
    
   hero a;
   cout << a.timeToComplete << endl;

   hero b;
   b.random();
   b.timeToComplete = 20;

   b.random();
   a.random();
    
}