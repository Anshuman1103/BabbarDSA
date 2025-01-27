#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
    }

    ~Node(){
        int value = data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Removing the node of : "<< value<< endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    //if tail is null
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    Node* temp = new Node(d);
    Node* curr = tail;
    while (curr->data != element)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout <<"The list is null" <<endl;
        return;
    }

   do{
    cout << tail->data << " ";
    tail = tail->next;
   }while(temp != tail);
   cout << endl;
    
}

void deleteNode(Node* &tail, int elementToDelete){
    //list is null
    if(tail == NULL){
        cout << "The list is empty "<<endl;
        return;
    }

    //assuming the node is present in the list
    Node* pre = tail;
    Node* curr = pre->next;

    //only single node in the list
    if(curr == pre){
        tail = NULL;
        return;
    }
    //more than one nodes 
    while (curr->data != elementToDelete)
    {
        pre = curr;
        curr = curr->next;
    }
    pre->next = curr->next;
    if (curr == pre)
    {
        tail = NULL;
    }
    if(tail == curr){
        tail = pre;
    }
    curr->next = NULL;
    delete curr;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 5 , 3);
    print(tail);

    insertNode(tail,  3, 5);
    print(tail);

    insertNode(tail, 3 , 7);
    print(tail);

    insertNode(tail, 3 , 10);
    print(tail);

    deleteNode(tail, 3);
    print(tail);


}