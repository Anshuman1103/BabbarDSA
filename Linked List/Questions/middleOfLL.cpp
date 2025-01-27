#include<iostream>
using namespace std;

//if odd then just mid but if even no. of elements them return upperbound of the half of the total number of the elements like if 5 then 3 , if 6 then 4

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

Node* getMidByLOOP(Node* head, int length){
    int count = (length/2) + 1;
    Node* temp = head;
    while (count != 1)
    {
        temp = temp -> next;
        count--;
    }
    return temp;
}

int main(){
    Node* head = new Node(8);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    //cout << getLength(head) << endl;
    Node* ans = getMidByLOOP(head, getLength(head));
    cout << ans->data << endl;
}