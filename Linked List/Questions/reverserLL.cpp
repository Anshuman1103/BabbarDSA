#include<iostream>
using namespace std;

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

Node* reverserLLByLoop(Node* &head){
    if(head == NULL && head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* forward = NULL;
    Node* prev = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void reverseLLByRecursion(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return ;
    }
    Node* forward = curr->next;
    reverseLLByRecursion(head, forward, curr);
    curr->next = prev;
}

Node* reverse3(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* chotaHead = reverse3(head->next);
    head ->next -> next = head;
    head -> next = NULL;

    return chotaHead;
}

int main(){
    Node* head = new Node(8);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    print(head);
    //head = reverserLLByLoop(head);
    Node* curr = head;
    Node* prev = NULL;
    reverseLLByRecursion(head, curr, prev);
   //reverse3(head);   some error is here
    print(head);
}