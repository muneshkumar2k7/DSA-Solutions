#include <iostream>
#include <iterator>
#include <climits>
int neg_inf = INT_MIN;
int pos_inf = INT_MAX;

using namespace std;

class Node{
public:
    int value;
    Node * next;
    Node * prev;

    Node(int v){
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
   Node * tail;

 Link_list(){
    head = nullptr;
    tail = nullptr;
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

};


// Linear Search Basic
int LS(int arr[], int len,  int num){
for(int i=0;i<len;i++){
    if(arr[i]==num)
      return i;
}
return -1;
}

// Sentinel LS
int Sentinel_LS(int arr[], int len, int num){
    int last = arr[len-1];
    arr[len-1] = num;
   int i=0;
    while(arr[i] !=num){
        i++;
    }

    arr[len-1] = last;
    if(i<len-1 || last == num)
      return i;

      return -1;
}
// Last Occurence
int Last_Occurence_LS(int arr[], int len, int num){
    int ind = -1;
    for(int i=0;i<len;i++){
    if(arr[i]==num)
      ind = i;
}
return ind;
}
// All occurence
int All_occurence(int arr[], int len, int num, int occurence[], int occur_len){
   int ind = -1;
    for(int i=0;i<len;i++){
    if(arr[i]==num)
      occurence[occur_len]= ind;
      occur_len++; 
}
return occur_len;

}

// Range Search
int range_search(int arr[], int len, int num, int start , int end){
  if(start >= 0 && end < len && start < len && start <=end){
 for(int i=start;i<=end;i++){
    if(arr[i]==num)
     return i;
}
  }
   
return -1;

}


// Linear search in string 
int LS_string(string Word , char letter){

  for(int i=0; i<Word.length();i++){
    if(letter == Word[i])
       return i;
  }

  return -1;
};


bool LS_td(int **arr, int n, int m , int val){
  bool found = false;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(arr[i][j]== val) found= true;
  }
}

return found;
}

bool Rec_LS(int ind, int arr[] , int val, int len){
if(ind >= len) 
  return false;


if(arr[ind] == val) return true;

return Rec_LS(ind+1, arr,val,len);
}


bool List_LS(Link_list L, int val ){
if(L.head == NULL) return false;

Node * ptr = L.head;

while(ptr !=NULL){
  if(ptr->value == val)  return true;

  ptr = ptr->next;
}

return false;
}

// Search for min 
int MIN_LS(int arr[], int len){
int min = pos_inf;
for(int i=0;i<len;i++){
if(arr[i] < min){
  min = arr[i];
}}
return min;
}

// Search for max
int Max_LS(int arr[], int len){
int max = neg_inf;
for(int i=0;i<len;i++){
if(arr[i] > max){
  max = arr[i];
}}

return max;
}

// Search for second max
int Max_LS(int arr[], int len){
int max = neg_inf;
int second_max = neg_inf;
for(int i=0;i<len;i++){

if(arr[i] > max){
  second_max  = max;
  max = arr[i];
}}

return second_max;
}
// Search for second min
int MIN_LS(int arr[], int len){
int min = pos_inf;
int second_min = pos_inf;
for(int i=0;i<len;i++){
if(arr[i] < min){
  second_min = min;
  min = arr[i];
}}
return second_min;
}

int main(){


    return 0;
}

