#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }

    ~Node(){
        int value = data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout <<"Freeing the memory of "<< value << endl;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count ;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
    
}

void insertAtTail(Node* head, Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d, int position){
    if(position == 1){
        insertAtHead(head,tail, d);
        return;
    }

        Node* temp = head;
        int count = 1;
        while(count < position-1){
            count++;
            temp = temp->next;
        }
        if(temp->next == NULL){
        insertAtTail(head,tail, d);
        return;
        }
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        nodeToInsert->prev = temp;
        temp->next = nodeToInsert;
    
}

void deleteAtPosition(Node* &head,Node* &tail, int position){
    if(position == 1){
        //deleting form first position
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        int count = 1;
        Node* pre = NULL;
        Node* curr = head;
        while(count < position){
            pre = curr;
            curr = curr-> next;
            count++;
        }
        if(curr->next == NULL){
            tail = pre;
            curr->prev = NULL;
            tail->next = NULL;
            delete curr;
            return;
        }
       pre->next = curr->next;
       curr->next = NULL;
       curr->prev = NULL;
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, tail, 5);
    print(head);
    cout <<"Head :" << head->data <<endl;
    cout <<"Tail :" << tail->data << endl;

    insertAtHead(head, tail, 8);
    print(head);
    cout <<"Head :" << head->data <<endl;
    cout <<"Tail :" << tail->data << endl;

    insertAtTail(head ,tail, 10);
    print(head);
    cout <<"Head :" << head->data <<endl;
    cout <<"Tail :" << tail->data << endl;

    insertAtPosition(head, tail , 7, 1);
    print(head);
    cout <<"Head :" << head->data <<endl;
    cout <<"Tail :" << tail->data << endl;

    insertAtPosition(head, tail , 9, 5);
    print(head);
    cout <<"Head :" << head->data <<endl;
    cout <<"Tail :" << tail->data << endl;

    deleteAtPosition(head,tail, 5);
    print(head);
    cout <<"Head :" << head->data <<endl;
    cout <<"Tail :" << tail->data << endl;
    
}