#include <iostream>
using namespace std;

class hashing{
 
 
  public:
int hash[10] = {0};

  hashing(){
    
  };

  void add_value(int x){
     int num = x % 10;
     if(!hash[num]){
      hash[num] = x;
     }else{
        cout<<"already filled"<<endl;
     }
     
  };

  void remove_value(int val){
     for(int i=0;i<10;i++){
        if(hash[i]== val){
            hash[i]=0;
        }
     }
  };
   
  
};
int main(){
   hashing h1;
   h1.add_value(10);
   h1.add_value(10);
   h1.add_value(11);
   h1.add_value(12);


   // searching 
   
   int num;
   cin >> num;

   int ind = num%10;
    
    if(h1.hash[ind] == num){
        cout<< num <<"exists" <<endl;
    }else{
        cout<< "Didn't Exist"<<endl;
    }

    return 0;
}