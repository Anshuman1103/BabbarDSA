#include<iostream>
using namespace std;

//HOLD
//Reverse the linked list in the group of k
//Lecture 46  

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

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        length++;
    }
    return length;
}

int main(){
    Node* head = new Node(8);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    
}