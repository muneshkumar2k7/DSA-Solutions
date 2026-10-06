#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head , int value){
Node* temp = head;

  Node* newNode = new Node;
    newNode->data = value;

while(temp->next != nullptr)
    temp = temp->next;

temp->next = newNode;
newNode->next = nullptr;
}

void insertAtIndex(Node* &head , int value , int index){
    Node * newNode = new Node;
    newNode->data = value;
     
    Node *temp = head;
    for(int i = 0; i < index - 1; i++)
    temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforeValue(Node*& head, int value, int target) {
     Node* newNode = new Node;
    newNode->data = value;

    if(head->data == target){
         newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != target){
        temp = temp->next;
    }


    if(temp->next == nullptr)
        return;

    newNode->next = temp->next;
    temp->next = newNode;
}


void insertAfterValue(Node*& head, int value, int target) {
     Node* newNode = new Node;
    newNode->data = value;
   
    if (head == nullptr)
    return;

    if(head->data == target){
         newNode->next = head->next;
        head->next = newNode;
        return;
    }

    Node* temp = head;
    while(temp != nullptr && temp->data != target){
        temp = temp->next;
    }

    if (temp == nullptr)
    return;

     newNode->next = temp->next;
   temp->next = newNode;
}


void insertIfNotExists(Node*& head, int value) {
    if (head == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->data == value)
            return;

        temp = temp->next;
    }
    
    if(temp->data == value) return;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;


    temp->next = newNode;
}


void insertBeforeAll(Node*& head, int value, int target) {
    if (head == nullptr)
        return;

    // Handle target at head
    while (head != nullptr && head->data == target) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    Node* temp = head;

    while (temp != nullptr && temp->next != nullptr) {
        if (temp->next->data == target) {
            Node* newNode = new Node;
            newNode->data = value;

            newNode->next = temp->next;
            temp->next = newNode;

            temp = newNode->next;  // move past target
        }
        else {
            temp = temp->next;
        }
    }
}

void insertBeforeTail(Node*& head, int value) {
    if (head == nullptr)
        return;

    // Only one node
    if (head->next == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;
}


void insertBeforeFirstOccurrence(Node*& head, int value, int target) {
    if (head == nullptr)
        return;

    Node* newNode = new Node;
    newNode->data = value;

    // Target is at head
    if (head->data == target) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Find the node before the FIRST occurrence
    while (temp->next != nullptr && temp->next->data != target) {
        temp = temp->next;
    }

    // Target not found
    if (temp->next == nullptr)
        return;

    // Insert before target
    newNode->next = temp->next;
    temp->next = newNode;
}
int main(){
    return 0;
}

