#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class QueueUsingLL{
    Node* start = NULL;
    Node* end = NULL;
    int size = 0;

    public:
    void push(int d){
        Node* temp = new Node(d);
        cout << "Pushing "<< d << endl;
        if(size == 0){
            end = temp;
            start = temp;
            size++;
            return;
        }
        end -> next = temp;
        end = temp;
        size++;
    }

    void pop(){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }
        cout <<"Deleting "<< start->data<< endl;
        Node* temp = start;
        start = start -> next;
        size--;
        delete temp;
    }

    void getSize(){
        cout <<"Size : "<< size << endl;
    }

    void getStart(){
        if(size == 0){
            cout << "NULL" << endl;
            return;
        }
        cout <<"Start = " << start -> data << endl;
    }

    void printQueue(){
        Node* temp = start;
        cout << "Printing elements : ";
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main() {
    QueueUsingLL q;
    q.push(2);
    q.push(5);
    q.printQueue();
    q.getSize();
    q.getStart();
    q.pop();
    q.getStart();
    q.push(8);
    q.printQueue();
    q.getSize();
    q.getStart();
    q.pop();
    q.pop();
    q.pop();
    return 0;
}