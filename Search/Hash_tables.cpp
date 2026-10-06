#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
int val; 
Node * next; 

Node(int val){
    next = NULL;
    this-> val = val;
}
Node(){};
int add_val(int val){
    this->val = val;
}

};
double load_factor(int size , int count){
return double(count)/size;
};

int hashFunction(int key){
return key%10;
};

int second_hash(int key){
    return 7 - (key % 7);
}

int var_hash(int key , int len){
return key % len;
}

bool lookup(int key , int **arr,int count[],int value){
int index = hashFunction(key);
int total = count[index];

for(int i=0;i<total;i++){
if(arr[index][i] == value) return true;
}

return false;
}

int distance(int current_pos , int ideal_pos , int len){
    return (current_pos - ideal_pos + len)%len;
}

void linear_probing(int arr[],  int keys[] ,int len , int number_of_keys){

for(int i = 0; i < len; i++)
    arr[i] = -1;

for(int i=0;i<number_of_keys;i++){
int index= var_hash(keys[i],len);
int j= 0;

while(j < len  && arr[(index+j) %len] != -1){
j++;
}

if(j < len)
    arr[(index+j) % len] = keys[i];
       
}

}

void Quadratic_probing(int arr[],  int keys[] ,int len , int number_of_keys){

for(int i = 0; i < len; i++)
    arr[i] = -1;

for(int i=0;i<number_of_keys;i++){
int index= hashFunction(keys[i]);

for(int j=0;j<len;j++){
   int position = (index + (j*j)) % len;

if(arr[position] == -1){
 arr[position] =   keys[i];
  break; 
}
}      
}

}

void double_hash(int arr[],  int keys[] ,int len , int number_of_keys){
for(int i = 0; i < len; i++)
    arr[i] = -1;

for(int i=0;i<number_of_keys;i++){
int index= hashFunction(keys[i]);
int second_ind = second_hash(keys[i]);
for(int j=0;j<len;j++){
   int position = (index + (j*second_ind)) % len;

if(arr[position] == -1){
 arr[position] =   keys[i];
  break; 
}
}      
}

}


int * resize(int size){
int * Resized_array = new int[size+10];
for(int i=0;i<size+10;i++)
    Resized_array[i]=-1;


 return Resized_array;   
}

void swap(int &a, int &b){
int temp = a;
a = b;
b = temp;
};

void rehash(int Array[], int len){
int * newTable = resize(len);
int newLen = len +10;


for(int i=0;i<len;i++){
    
    if(Array[i] == -1)
      continue;
     int index = var_hash(Array[i], newLen);
   
    for(int j=0;j<newLen;j++){
     int step =second_hash(Array[i]);
     int position = (index + (step * j) )%newLen;

if(newTable[position] == -1){
    newTable[position] = Array[i];
    break;
}
    }
   
}

}

// Robin Hood Hashing 
void Robin_hood(int arr[], int len , int values[], int number_of_values){

for(int i=0;i<number_of_values;i++){
   
 int  current_Key = values[i];
int ideal_index= var_hash(current_Key, len);
int current_pos = ideal_index;


 for(int j=0;j<len;j++){

    if(arr[current_pos] == -1){
        arr[current_pos] = current_Key;
        break;
    }else{

    int current_index = var_hash(arr[current_pos],len);
    int d = distance(current_pos,ideal_index, len);
    int new_d = distance(current_pos, current_index, len);


   if(d > new_d){
    swap(current_Key, arr[current_pos]);
        // currentKey is now the displaced key
        ideal_index = var_hash(current_Key, len);
   }
current_pos = (current_pos + 1) % len;
}
 }}}

int hash_one(int key, int table_size, int version)
{
    if(version == 1)
        return key % table_size;

    if(version == 2)
        return (key + 7) % table_size;

    return (key + 13) % table_size;
}

int hash_two(int key, int table_size, int version)
{
    if(version == 1)
        return (3 * key + 1) % table_size;

    if(version == 2)
        return (5 * key + 3) % table_size;

    return (7 * key + 11) % table_size;
}
 bool cuckoo_hashing(int input_arr[], int len ,int table[], int table_size , int version){


    for(int i=0;i<len;i++){
        int current = input_arr[i];
        int H_one = hash_one(current,table_size,version);
        int position_type = 1;

         int  *current_key = &table[H_one];
         int kicks = 0;
         int n;
      while(*current_key != -1  && kicks < table_size){
         n = *current_key;
         int Hash_func ;
         if(position_type ==1){
         Hash_func= hash_two(n,table_size,version); 
        }else{
         Hash_func= hash_one(n,table_size,version);
        }

         *current_key = current;
         current = n;
         current_key = &table[Hash_func];

         position_type = (position_type == 1) ? 2 : 1;

         kicks++;
      }
     if(*current_key ==-1){
            *current_key = current;  
     }

      if(kicks == table_size) return false;
        }

        return true;
    }
   
 



   void new_rehash(int table[], int table_size,int arr[], int len, int version){
{
    while(true)
    {
        for(int i = 0; i < table_size; i++)
            table[i] = -1;

        version = (version % 3) + 1;

        if(cuckoo_hashing(arr, len, table, table_size, version))
        {
            cout << "Rehashed successfully" << endl;
            return;
        }

        cout << "Repeat" << endl;
    }
}
}







// Perfect Hashing is the concept in which we design the after watching all keys and keys should be static / fixed it is not 
// neccessary after adding key the hash function is still correct some times you need to create another hash function that is perfect hashing 







// It is just check key existance ... it is used for removing dulplicacy if key exist then don't add again 

bool Existance_lookup(int keys[],int s, int number_of_keys, int k){
    for(int i=s;i<number_of_keys;i++){
    if(keys[i] == k) return true;
    }
    return false;
}


// frequency Lookup
int Freq_lookup(int keys[], int number_of_keys, int k){
    int frequency= 0;
    for(int i=0;i<number_of_keys;i++){
    if(keys[i] == k) frequency++;
    }
    return frequency;
}


bool Sum(int array[], int len ,int tar){
    int current =0;
    int comp = 0;
for(int i = 0;i<len-1 ;i++){
  current = array[i];
   comp = tar  - current;
 if(Existance_lookup(array,i+1,len,comp)) return true;
}

return false;
}

// Four LookUp techniques we have learned existence , frequency , complement ,direct now we do question on each 


int ExactLookup(int keys[], int values[], int len, int targetKey){
    int index= -1;

 for(int i=0;i<len;i++){
    if(keys[i] == targetKey){
      index = i;
    }
 }   

 if(index == -1){
    return index;
 }else{
  return values[index];
 }

}




bool Two_pointer(int sorted[], int start , int end , int target){
if(start >= end) return false;

int sum = sorted[start] + sorted[end];

if( sum == target) return true;

    if(sum > target ){
        end--;
        return Two_pointer(sorted , start , end, target);
    }else{
         start++;
        return Two_pointer(sorted , start , end, target);
    }

}

bool check_distant_element(int arr[], int len , int k){
    if(k > len) return false;
int left = 0;
int right = k;
int comp = 0;
while(right < len){
right= left+k;
 int current = arr[left];
 if(Existance_lookup(arr,left+1,right+1,current)) return true;  
left++;
}
return false;
}



int unique_elements(int arr[], int s ,int e , int element){
int freq = 0;
for(int i=s;i<=e;i++){
if(arr[i] > element) freq++;
}

return freq;
}
int max_element(int arr[], int len){
    int max = 0;
    for(int i=0;i<len;i++){
    if(arr[i]> max) max = arr[i];
    }

    return max;
}

int longestSubarray(int arr[], int len, int K){
    int length = max_element(arr,len);
int freq[length+1] = {0};
int left = 0;
int right = 0;
int unique= 0;
int ans = 0;

while(left < len && right < len){

  freq[arr[right]]++;


     if (freq[arr[right]] == 1)
        unique++;

while(unique > K){
    freq[arr[left]]--;
    

    if (freq[arr[left]] == 0)
        unique--;

   left++;

}

   int window_size = right - left +1;

   if(window_size > ans) ans = window_size;

    right++;


} 

return ans;
    }
   
   


  



















int main(){
    
Node n1;

Node * Table[10] = {NULL};

int *Arr = new int[5];



    int arr[4] ={1010, 1021, 1032, 1043};
    int keys[4]= {120,121,122,123};
   string names[]= {"Rakesh", "Hearsh","Ramesh","Varun"};

 // insertion 
for(int i=0;i<4;i++){
    
  if(Table[hashFunction(arr[i])] == NULL){
    Table[hashFunction(arr[i])] = new Node(keys[i]);
  }else{  
   Node * ptr = Table[hashFunction(arr[i])];
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
   ptr->next = new Node(keys[i]);
  }
  
}

vector <int> bucket[10];
int array_bucket[4][10];
int count[10] = {0};

for(int i=0;i<4;i++){
    bucket[hashFunction(arr[i])].push_back(keys[i]); 
}

for(int i=0;i<4;i++){
    int index = hashFunction(arr[i]);
  array_bucket[index][count[index]] = keys[i];
  count[index]++;
}




    for(int i=0;i<4;i++){
        cout << hashFunction(keys[i]) << endl;
    }

    return 0;
}