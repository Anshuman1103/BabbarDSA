#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class StackUsingLL{
    Node* top = NULL;
    int size = 0;

    public:
    void push(int d){
        Node* temp = new Node(d);
        temp -> next = top;
        top = temp;
        size++;
    }

    void pop(){
        Node* temp = top;
        top = top -> next;
        size--;
        delete temp;
    }

    void getSize(){
        cout <<"Size : "<< size << endl;
    }

    void getTop(){
        if(top == NULL){
            cout << "NULL" << endl;
            return;
        }
        cout <<"TOP = " << top -> data << endl;
    }

    void printStack(){
        Node* temp = top;
        cout << "Printing elements : ";
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main() {
    // Your code here
    StackUsingLL st;
    st.push(5);
    st.push(6);
    st.printStack();
    st.getSize();
    st.getTop();
    st.pop();
    st.printStack();
    st.getSize();
    st.push(10);
    st.printStack();
    st.getTop();
    return 0;
}