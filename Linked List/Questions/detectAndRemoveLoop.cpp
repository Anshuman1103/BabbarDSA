#include<iostream>
#include<map>
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

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;
    while (temp != NULL)
    {
        if(visited[temp] == true)
            return true;
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

Node* floydCycleDetectionAlgo(Node* head){
    //This algo use the concept of slow and an fast pointer to detect whether the loop is present in the LL or not

    // How it's work = when they both are in loop then har ek itertion ke sath inke beech ka distance kam hota jata hai

    if(head == NULL){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    while (slow != NULL & fast != NULL)
    {
        fast = fast->next;
        if(fast == NULL){
            return NULL;
        }
        fast = fast->next;
        slow = slow->next;
        if(slow == fast){
            return fast;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydCycleDetectionAlgo(head);
    Node* slow = head;
    Node* fast = intersection;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

void removeLoop(Node* head){
    if(head == NULL) return ;
    Node* start = getStartingNode(head);
    Node* temp = start;
    while (temp -> next != start)
    {
        temp = temp -> next;
    }
    cout << "Loop is being removed by " << temp->data << endl;
    temp -> next = NULL;
}

int main(){
    Node* head = new Node(8);
    Node* tail = head;
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    tail->next = head ->next -> next;

    //print(head);
    // if(detectLoop(head)){
    //     cout<<"Loop is present" << endl;
    // }
    // else{
    //     cout<<"Loop is absent" << endl;
    // }

     if(floydCycleDetectionAlgo(head) != NULL){
        cout<<"Loop is present" << endl;
        cout<<"Loop at : " << getStartingNode(head)->data<< endl;
        removeLoop(head);
        print(head);
    }
    else{
        cout<<"Loop is absent" << endl;
    }

}