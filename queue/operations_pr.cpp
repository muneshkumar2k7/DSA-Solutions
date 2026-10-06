#include <iostream>

class Queue{
  int size;
  int * array;
  int front = -1;
  int rear =-1; 

  public:

  Queue(int s){
    size  = s;
   array = new int[size];
  }

  bool isEmpty(){

    if(rear == -1 )
        return true;
    else
        return false;
    
  }

  bool isFull(){

   if(rear == size-1)
    return true;
   else
    return false;
   
  }

  void Enqueue(int val){
   if(isFull()){
    cout <<"Queue is Full"<<endl;
    return;
   }else{
    if(rear == -1){front++;}
    rear++;
    array[rear]= val;
   }
  }

  void Dequeue(){
   if(isEmpty()){
    cout << "Queue is Empty"<<endl;
    return;
   }
   
   if(front == rear){
     front =-1;
    rear =-1;
   }else{
        front++;
   }

  }
  
  int front_element(){
    if(isEmpty()){
        return  -1;
    }else{
      return array[front];
    }
  }

};
 
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

}


class LQueue{
    Node * rear;
    Node * front;
public:

LQueue(){
front = rear = NULL;
};

void Enqueue(NOde * newNode){
if(rear == NULL){
    front =rear = newNode;
}else{
   rear->next = newNode; 
   rear = newNode;    
}
}

void Dequeue(){
if(rear == NULL){
 cout <<"is Empty"<<endl;
 return;
}
  
if(front == rear){
    front = rear = NULL;
}else{
    front = front->next;
}
}



int front_element(){
  if(front == NULL){
    cout <<"Queue is empty";
    return -1;
  }else{
    return front->val();
  }

}

};













// Doubly linklist Queue Song Playlist Implementation Task
class Song{

    string title; 
    public:
    Song * next;
    Song * prev;

    Song(string t){
        next = prev = NULL;
        title = t;
    }
    string Song_Name(){
        return title;
    }
};

class Playlist{
    Song * front;
    Song * rear;
    
    public:
    Playlist(){
    front = rear = NULL;
    }
   
    string Print_current_song(){
        if(front == NULL){
            return "No Song Available";
        }else{
            return front->Song_Name();
        }
    }

    void Add_Song(Song * NewSong){
      if(rear == NULL){
        front = rear = NewSong;
      }else{
        NewSong->next = front;
        front->prev = NewSong;
        front = NewSong;
      }
    }

    void Rmv_Song(){
   if(rear == NULL){
    cout <<" Playlist is Empty";
    return;
   }

   if(front == rear){
    front = rear = NULL;
   }else{
    front = front->next;
   }
    }
   
   void Move_to_specific_song(string t){
     if(rear == NULL){
        cout <<" Playlist is Empty";
        return;
     }

     if(front->Song_Name() == t)
      return;

    Song * temp = front;

    while(temp != NULL && temp->Song_Name() != t){  
        temp =temp->next;
    }

    front = temp;

    }

};


int main(){



}