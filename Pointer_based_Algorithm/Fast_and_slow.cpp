#include <iostream>
using namespace std;
Node{
Node * next;
int data;
};

Node * middle_of_link_list(Node *head){

    Node * Fast = head;
    Node * slow = head;

    while(Fast != nullptr && Fast->next != nullptr){
        Fast = Fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool has_Cycles(Node * head){
  Node * Fast = head;
    Node * slow = head;


    while(Fast != nullptr && Fast->next !=nullptr ){
        Fast = Fast->next->next;
        slow = slow->next;

        if(Fast == slow)
          return true;
    }

    return false;

}

Node* cycleStart(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow ->next;

        if(slow == fast){
            slow = head;
            
              while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
}


Node * isPalinedrome(Node *head){

    Node * Fast = head;
    Node * slow = head;

    while(Fast != nullptr && Fast->next != nullptr){
        Fast = Fast->next->next;
        slow = slow->next;
    }

    Node * curr = slow;
    Node * prev  = nullptr;

    while(curr != nullptr){
        Node *next = curr->next;
        curr->next  =prev;
        prev = curr ;
        curr = next;
         
    }

Node * ptr1 = prev;
Node * ptr2 = head;

while(ptr1 != nullptr && ptr2 != nullptr){
    if(ptr1->data != ptr2->data){
        return false;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
}
return true;
}


vector<int>Remove_duplicate_from_sorted(int arr[], int size){
    vector <int> result;

    if(size ==0) return result;
  

    int fast= 0;
    int slow= 0;
    
   result.push_back(arr[slow]);

    while(fast < size){

    if(arr[slow] !=arr[fast]){
        result.push_back(arr[fast]);
        slow = fast;
    }
        fast++; 
    }

    return result;
}

void Move_zeroes(int arr[], int size){
    int fast = 0;
    int slow = 0;

    while(fast < size){
        if(arr[fast]){
         arr[slow] = arr[fast];
         slow++;
        }

        fast++;
    }

    while(slow < size){
        arr[slow] =0;
        slow++;
    }
}


int main(){

}