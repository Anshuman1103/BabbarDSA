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

    hero(int h , char c){
        this->health = h; // this is a pointer that stores the address the current object
        this->level = c;
    }
    //copy constructor (we can also create it manually)
    hero(hero& temp){// pass by reference is neccesary bcz otherwisi it will got stuck inot infinite loop due to calling of copy costuctor continously

        //this will produce deep copy
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);

        this->health = temp.health;
        this->level = temp.level;
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

//in case of empty class the instance will get 1 byte in order to keep track of the object
//We can also create class as different file and then include them in any file to use it. by #include"hero.cpp".

int main(){

    //static allocation
    hero h1;
    cout << sizeof(h1) << endl;

    //Dynamic allocation
    hero *h = new hero; //same as -> hero *h = new hero();

    h->setHealth(10); // same as (*h).setHealth
    h->setLevel('A');
    cout << "Health :" << (*h).getHealth() << endl;
    cout << "Level : " << (*h).getLevel()<< endl;

    cout <<"Copy constructor"<< endl << endl;

    hero h2( 10 , 'C');
    h2.print();
    hero h3(h2); //copy constructor or hero h3 = h2(assignment operator)
    h3.print();

    //Deep copy and shallow copy
    //copy constructor will create a shallow copy mean any change in the previous data will also change the copied one .

    //destructor
    hero a;

}