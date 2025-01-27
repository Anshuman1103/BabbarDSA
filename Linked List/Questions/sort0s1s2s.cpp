#include<iostream>
using namespace std;

// there were 0s, 1s and 2s in the LL , arrange them in ascending order

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        //Memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for : "<<value<< endl; 
    }
};

void insertAtHead(Node* &head, int n){
    Node* temp = new Node(n);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int n){
    Node* temp = new Node(n);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    Node* tail = head;
    insertAtHead(head, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    print(head);
   
}