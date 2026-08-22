#include <iostream>
using namespace std;

class Queue{
 int arr[10];    
 int front,rear;


 public:

 Queue(){
    front = 0;
    rear = 0;  
 } 

bool empty(){
    return front == rear;
}

int size(){
    return rear - front;
}

void enqueue(int x){
    if(rear < 10){
       arr[rear++] = x;
    }else{
        cout<<"Queue is Overflow"<<endl;
    }
}

void dequeue(){
    if(!empty()){
     front++;
    }else{
        cout<<"Queue is UnderFlow"<<endl;
    }
}

    int Front() {
        if (!empty())
            return arr[front];

        cout << "Queue is Empty\n";
        return -1;
    }

    void display() {
        for (int i = front; i < rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }



};

int main(){

     Queue q1;
     q1.enqueue(1);
     q1.enqueue(2);
     q1.enqueue(3);
     q1.enqueue(4);


     int num;
cin >> num;

bool found = false;
int sz = q1.size();

for (int i = 0; i < sz; i++) {
    int x = q1.Front();

    if (x == num)
        found = true;

    q1.dequeue();
    q1.enqueue(x);   // Put it back
}
    return 0;
}
