#include <iostream>
using namespace std;
// Singly link_list Node
class Node{
    public:
    int value;
    Node * next;

    Node(int v) : value(v){
        next = nullptr;
    }
   Node() {
        value = -1;
        next = nullptr;
    }
};
// Doubly Linked List Node
class D_Node{
public:
    int value;
    D_Node * next;
    D_Node * prev;

    D_Node(int v){
        value = v;
        next = nullptr;
        prev = nullptr;
    }


};



class Link_list{
    public:
    // head for singly linklist
   Node *head;  
   //head for doubly linklist
   D_Node * D_head;
   D_Node * D_tail;

 Link_list(){
    head = nullptr;
    D_head = nullptr;
    D_tail = nullptr;
 }

 void add_node(Node *n1){

      if (head == nullptr) {
        head = n1;
        return;
    }

   Node *temp = head;

   while(temp->next !=NULL){
    temp = temp->next;
   }
   temp->next = n1;
 }
 

// Forward Traversal 

 void forward_traversal(){
   Node * ptr= head;
   
   while(ptr != NULL){
    cout << ptr->value << ",";
    ptr = ptr->next;
   }

 }


 // Backward Traversal is only possible in Doubly linked list

 void add_D_node(D_Node *n1){
   
    if (D_head == nullptr) {
        D_head = n1;
        D_tail  = n1;
        n1->prev = nullptr;
        n1->next = nullptr;
        return;
    }

    D_Node * temp = D_head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
        n1->prev =temp;
        n1->next = nullptr;
        temp->next = n1;
        D_tail = n1;
 }

 // Backward Traversal 

 void Backward_traversal(){
    D_Node * temp = D_tail;
  
    while (temp != NULL)
    {
       cout << temp->value << ",";
       temp  = temp->prev;
    }
    
 }
};



// Recursive Traversal 

void  Traverse(Node * h1){
    if(h1 == NULL)
     return;

    cout << h1->value <<", " ;
    Traverse(h1->next);

}
// Reverse Traversal 

void reverse_traverse(D_Node * h1){
if(h1 == NULL)
return;

cout << h1->value;
reverse_traverse(h1->prev);
}



// Condition Traverse
void condition_traverse(Node * h1){

Node* temp = h1;

while(temp !=NULL){
    if(temp->value % 2 == 0) 
     cout << temp->value << " , "; 
    temp = temp->next;
}
}

// Two Pointer Slow and Fast Traversal Solve many problems
 // Now lets solve one of the problem through this technique find middle node
Node * Two_Pointer_Traverse(Node * h1){
 Node * fast = h1;
 Node * slow= h1;

    while(fast  && fast->next ){
     fast = fast->next->next;
     slow = slow->next;
    }
   return slow;
     
}

// Bidirectional Traversal with one pointer 
// means one link list 123 it will use bidirectional and print 123321
// commence...

void single_bidir_traverse(D_Node * h1){

    D_Node *temp = h1;
    D_Node * temp1;

    cout << endl;
    while (temp !=NULL)
    {
       cout << temp->value;
        temp1 = temp;
        temp = temp->next;
       
    }

     while (temp1 !=NULL)
    {
       cout << temp1->value;

        temp1 = temp1->prev;
    }
    

}


// Bidirectional Traversal and Two pointer palindrome check

void Palindrome_Check(D_Node * head , D_Node * Tail){
D_Node * right = Tail; 
D_Node * left = head;
bool not_pln;
while(right != NULL && left!= NULL ){
    if(left->value != right->value){
        not_pln =true;
        break;
    }
 right =right->prev;
 left = left->next;
}

if(not_pln){
    cout << "Not palindrome";
}else{
    cout <<"Palindrome";
}

}

// Circ Link list traversal


class Circ_link_list{

    public:
    // head for singly linklist
   Node *head;  
   //head for doubly linklist
   D_Node * D_head;
   D_Node * D_tail;

 Circ_link_list(){
    head = nullptr;
    D_head = nullptr;
    D_tail = nullptr;
 }

 void add_node(Node *n1){

      if (head == nullptr) {
        head = n1;
        n1->next = n1;
        return;
    }

   Node *temp = head;

   while(temp->next != head){
    temp = temp->next;
   }
   temp->next = n1;
   n1->next = head;
 }
    

 void add_D_node(D_Node * n1){
   
    if (D_head == nullptr) {
        D_head = n1;
        D_tail  = n1;
        n1->prev = n1;
        n1->next = n1;
        return;
    }

    D_Node * temp = D_head;

    while (temp->next != D_head)
    {
        temp = temp->next;
    }
        n1->prev =temp;
        n1->next = nullptr;
        temp->next = n1;
        D_tail = n1;
        D_head->prev = D_tail;
        D_tail->next = D_head;
 }

 void Circ_traverse(){
    Node *temp = head;

    if(temp != NULL){
    do{
    
     cout << temp->value;
    temp = temp->next;
    }while(temp !=head);

    }
    
 }



 void cycle_traverse(){
    Node * slow = head;
    Node * fast = head;

    while(fast && fast->next){
     fast= fast->next->next;
     slow = slow->next;

     if(slow == fast){
        cout << "cycle Found "<<endl;
        break;
     }
    }

 }
 };

 // Alternate Node Traversal
void alternate_node_traversal(Node * head){
    Node* temp = head; 
    while (temp) { cout << temp->value << " "; 
        if (temp->next) temp = temp->next->next; 
        else break; 
    }

}
// pairwise traverse
void pairwise_traverse(Node * head){
Node* temp = head;

 while (temp && temp->next) { 
    cout << temp->value << " " << temp->next->value << endl;
     temp = temp->next->next; 
    }

}
 
// For Dummy list // for Sentinel Traverse
class list_l {
public:
    Node Dummy;
    Node *head;

    list_l(){
        head = &Dummy;
    }

    void add_node(Node *n1) {

        if (Dummy.next == nullptr) {
            Dummy.next = n1;
            n1->next = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = n1;
        n1->next = nullptr;
    }
};

int main(){

    Node n1(5);
    Node n2(4);
    Node n3(3);

    D_Node D1(1);
    D_Node D2(2);
    D_Node D3(3);

  Link_list l1;
  l1.add_node(&n1);
  l1.add_node(&n2);
  l1.add_node(&n3);

  
  l1.forward_traversal();

  l1.add_D_node(&D1);
  l1.add_D_node(&D2);
  l1.add_D_node(&D3);

cout << endl;
// Backward Traversal for only Doubly but Forward only for singly because class is designed in this way 
  l1.Backward_traversal();

// Recursive Traversal
cout << endl;

Traverse(l1.head);
reverse_traverse(l1.D_tail);
cout << endl;
condition_traverse(l1.head);
cout << Two_Pointer_Traverse(l1.head)->value;
single_bidir_traverse(l1.D_head);

    D_Node CD1(1);
    D_Node CD2(2);
    D_Node CD3(3);







    return 0;

}