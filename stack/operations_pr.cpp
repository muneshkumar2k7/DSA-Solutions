#include <iostream>

// class stack using array

class stack{
    int size;
    int top = -1;
    int *array;
    
    public:
    int top_index(){
         return top;
    }

    stack(int s){
        size = s;
        array = new int[size];
    }

    int peek(){
       if(top == -1)
        return top;
       else 
        return array[top];
    }

    void push(int element){
     if(top == size-1){
        cout <<" Array is Full"<<endl;
     }else{
        top++;
       array[top] = element;
     }
    }

    void pop(){
    if(top != -1){
        top--;
    }else{
        cout <<"stack is empty";
    }
    }


    void Reverse_Stack(){
    if(top == -1) return;

    int first = 0;
    int second = top_index();


    while(first < second){
        swap(array[first], array[second]);
        first++;
        second--;
    }
}
};

// stack using Linklist

class Node{
    int data;
public:
     Node * next; 
    Node(int val){
     next = NULL;
     data = val;
    }
    int val(){
        return data;
    }

};




class LStack{
Node * top;
public:
LStack(){
    top = NULL;
}



void push(Node * newNode){
    newNode->next = top; 
    top = newNode; 
     
}

void pop(){
  if(top == NULL) {
    cout<<"Stack is empty";
    return;
  }else{
    top = top->next;
  }
}

int peek(){
    if(top == NULL){
        return -1;
    }else{
        return top->val();
    }

}
};


int  binary_search(int CGPA[] , int first , int last , int target){
   if(first > last){
     return -1;
   }

   int mid = first + (last-first)/2;

   if(target == CGPA[mid]) return mid;

   if(target <  CGPA[mid]){
     first = mid+1;
     return binary_search(CGPA,first,last,target);
   }else{
    last = mid-1;
     return binary_search(CGPA,first,last,target);
   }
    
}
int main(){
    return 0;
}