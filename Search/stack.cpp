#include <iostream>
using namespace std;

class stack{
    int arr[10];
    int length;
public: 
int size(){
    return length;
} 

stack(){length = 0;};

void push(int x){ 
    if(length < 10){
        arr[length] = x;
        length++;
    }else{
        cout<<"Stack OverFlow"<<endl;
    }
}

void pop(){
    length--;
}

int top(){
    return arr[length-1];
}
  
void view_stack(){
      for(int i = length; i>=0 ;i--){
       cout << arr[i] <<endl;
    }
}
};

int main(){

    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
     
    int num;
    cin>>num;
    
bool find = false;
    int size = s1.size();

    for(int i=0 ;i<size;i++){

        if(s1.top() == num){
            find = true;
            cout << i<< endl;
            break;
        }
        s1.pop();
    }
    

    if(!find){
        cout<<"Not Found"<<endl;
    }
    return 0;
}
