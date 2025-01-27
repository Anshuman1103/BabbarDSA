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

int main(){

    Node* node1 = new Node(3); //here node1 in the pointer
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node* head = node1;
    Node* tail = node1;
    // print(head);
    // insertAtHead(head, 12);
    // print(head);

    print(tail);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(head,tail, 4, 10);
    print(head);
    cout<< "Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    cout<<endl<<endl;
    deleteNode(head, 1);
    print(head);
}