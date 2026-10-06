#include <iostream>
using namespace std;
 
class hashing{
   public:

    int hash[10]={0};

    void add_value(int x){
        int index = x % 10;
       while(hash[index]){
        if (!hash[index]){
         hash[index] = x;
        };
          index = (index+1)%10;
       }
    }
};
int main(){

}