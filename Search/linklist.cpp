#include <iostream>
#include <iterator>

using namespace std;

class list{
     
    public:


    int value;
    list *next;

    list(int v , list *l1= nullptr ):value(v),next(l1){}
    int get_value(){return value;}
    list* get_ptr(){return next;}
    void add_ptr(list *ptr){
        this->next = ptr;
    }
  
};


int main(){

     list a1(5);
    list a2(10, &a1);
    list a3(25,&a2);


    
    int num;
    cin >> num;

     bool find = false;


      list * head = &a3;
    list *p = &a3;

    int i=0;
    while(p !=NULL){

      if(p->get_value() == num){
        find = true;
        cout<< i<<endl;
        break;
      }  
      p =p->next;
      i++;
    }

    if(!find) cout<< "NOT found"<<endl;
}