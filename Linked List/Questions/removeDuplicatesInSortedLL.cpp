#include<iostream>
using namespace std;

//HOLD

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

void removeDuplicates(Node* &head){
    if(head == NULL){
        return;
    }
    Node* curr = head;
    while (curr != NULL)
    {
        if((curr->next != NULL) && curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    }
    
}

int main(){
    Node* head = new Node(8);
    Node* tail = head;
    insertAtHead(head, 7);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    removeDuplicates(head);
    print(head);
}