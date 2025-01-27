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

void insertAtTail(Node* &tail, int n){
    Node* temp = new Node(n);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail,int position, int n){
    //inserting at first position
    if(position == 1){
        insertAtHead(head, n);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    //inserting at last position
    if(temp->next == NULL){
        insertAtTail(tail, n);
        return;
    }
    Node* nodeToInsert = new Node(n);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        //deleting form first position
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        int count = 1;
        Node* prev = NULL;
        Node* curr = head;
        while(count < position){
            prev = curr;
            curr = curr-> next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
// Example:
// Given linked list is 1 -> 0 -> 2 -> 1 -> 2.
// The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.


void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

int main(){
    Node* head = new Node(2);
    Node* tail = head;

    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    head = sortList(head);
    print(head);
}