#include <iostream>
using namespace std;

void insert_at_end(int arr[],int &size,int capacity, int val ){
if(size >= capacity){
 cout<<"Array is full"<<endl 
 return;
}else{
    arr[size] = val;
    size++;
}
};


void insert_at_beginning(int arr[], int &size , int capacity , int val ){
if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return ;
}else{

    for(int i=size-1;i>=0;i--){
    arr[i+1] = arr[i];
    }
    arr[0]= val;
}
};

void insert_at_index(int arr[], int &size , int capacity , int index , int val){
    // Complete Array
if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return ;
}

 if(index < 0 || index >size){
  cout << "Undefined Behaviour" << endl;
 } 
      for(int i=size-1;i>=index;i--){
    arr[i+1] = arr[i];
    }
    arr[index]= val; 

}
// this should be Unique array  
void insert_before_value(int arr[], int &size, int capacity , int sol ,int val){
int index = -1;
    if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return ;
}

for(int i=0;i<size;i++){
 if(arr[i] == val){ 
    index = i;
}
}
if(index == -1){
    cout<<" value doesn't Exist"<<endl;
    return ;
}

for(int i=size-1;i>=index;i--){
arr[i+1] = arr[i];
}
arr[index] = sol;
size++;
}

void insert_after_value(int arr[], int &size, int capacity , int sol ,int val){
    int index = -1;
    if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return ;
}

for(int i=0;i<size;i++){
 if(arr[i] == val) index = i+1;
}
if(index == -1){
    cout<<" value doesn't Exist"<<endl;
    return ;
}

for(int i=size-1;i>=index;i--){
arr[i+1] = arr[i];
}
arr[index] = sol;
size++;

}

// Occurence or Repeated Elements not unique Array


void insert_before_first_occurence(int arr[], int &size, int capacity , int sol ,int val){
int index = -1;
    if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return ;
}

for(int i=0;i<size;i++){
 if(arr[i] == val){ 
    index = i;
    break; // if I dont add break; then it will be before and after last occurence
}
}
if(index == -1){
    cout<<" value doesn't Exist"<<endl;
    return ;
}

for(int i=size-1;i>=index;i--){
arr[i+1] = arr[i];
}
arr[index] = sol;
size++;
}

void insert_after_first_occurence(int arr[], int &size, int capacity , int sol ,int val){
    int index = -1;
    if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return ;
}

for(int i=0;i<size;i++){
 if(arr[i] == val){
 index = i+1;
 break; // if I dont add break; then it will be before and after last occurence
 } 
}
if(index == -1){
    cout<<" value doesn't Exist"<<endl;
    return ;
}

for(int i=size-1;i>=index;i--){
arr[i+1] = arr[i];
}
arr[index] = sol;
size++;

} 


void insert_before_all_occurences(int arr[], int &size, int capacity , int sol ,int val){
    int index[200] = {0};
    int flag = 0;
    int index_length = size-1;


for(int i=0;i<size;i++){
 if(arr[i] == val){
 index[i] = 1;
 flag=1;
 } 
}

if(!flag){
    cout<<" value doesn't Exist"<<endl;
    return ;
}

while(index_length >= 0){

     if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return;
}

    if(index[index_length]){

    for(int i=size-1;i>=index_length;i--){
    arr[i+1] = arr[i];
    }
   arr[index_length] = sol; 
   size++;

    }

index_length--;
}

} 

bool exists_val(int arr[], int len, int val){
for(int i=0;i<len;i++){
    if(arr[i]==val) return true;
}

return false;
}

// conditional Insertion you can use any condition but in the below solution we will use exists and not exists
void conditional_insertion(int arr[], int &size , int capacity ,int val){
if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return;
}

if(!exists_val(arr,size,val)){
    arr[size] = val;
    size++;
}

}

// Linear position search both techniques Ascending and descending 
// Insert in sorted ascending order 
void Insert_In_sorted_ascending(int arr[], int &size, int capacity , int val){
int index= -1;
    if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return;
}


for(int i=0;i<size;i++){
  if(arr[i] > val) {index= i; break;}
}

if(index == -1){
    arr[size] = val;
    size++;
    return;
}

for(int i=size-1;i>=index;i--){
arr[i+1] = arr[i];
}
arr[index] = val;
size++;

}

void Insert_In_sorted_descending(int arr[], int &size, int capacity , int val){
int index= -1;
    if(size >= capacity){
    cout <<"Array is Full"<<endl;
    return;
}


for(int i=0;i<size;i++){
  if(arr[i] < val) {index= i; break;}
}

if(index == -1){
    arr[size] = val;
    size++;
    return;
}

for(int i=size-1;i>=index;i--){
arr[i+1] = arr[i];
}
arr[index] = val;
size++;

}



// Binary position Search
int Binary_pos_search(int arr[], int start , int end , int val){
    // NOt Found 
if(start > end ) return start;

int mid = start + (end-start)/2;

// already available 
if(val == arr[mid]) return mid;

if(val > arr[mid]){
    start = mid+1;
   return  Binary_pos_search(arr, start ,  end , val);
}else{
    end= mid-1;
   return Binary_pos_search(arr, start ,  end ,  val);
}
}


int UpperBound(int arr[], int start , int end , int val ,int index ){
    if(start > end) return index;

int mid = start + (end-start)/2;

if(val >= arr[mid]){
    index = mid+1;
    start = mid+1;
   return  UpperBound(arr, start ,  end , val, index);
}else{
    index = mid;
   return UpperBound(arr, start , mid -1 ,  val , index);
}

}


int LowerBound(int arr[], int start , int end , int val , int index){
    if(start > end ) return index;

    int mid = start+(end - start)/2;

    if(val <= arr[mid]){

     index = mid;
    end = mid-1;
   return  LowerBound(arr, start ,  end , val, index);

    }else{
     
    index = mid+1;
    return LowerBound(arr, mid+1, end ,  val , index);
}
    
}

int find_freq(int arr[], int start , int end ,int e , int length){
int freq = 0;

for(int i=start ;i<end ; i++){
    if(arr[i] == e) freq++;
}
return freq;
}

int find_first_dup_index(int arr[], int length ){

for(int i=0;i<length-1;i++){
 int num = arr[i];

 if(find_freq(arr,i+1,length,num,length)){
    return i;
 }
}
return -1;
}

int find_last_dup_index(int arr[], int length ){

for(int i=length-1;i>=0;i--){
 int num = arr[i];

 if(find_freq(arr,0,i-1,num,length)){
    return i;
 }
}
return -1;
}


void Before_First_Dup(int arr[], int &length ,int val){

    int index = find_first_dup_index(arr,length);
if(index == -1) return;
    for(int i = length-1;i>index;i--){
        arr[i] = arr[i-1];
    }
    arr[index] = val;
    length++;
}


void After_last_Dup(int arr[], int &length ,int val){
 int index = find_last_dup_index(arr,length);

 if(index == -1){
    return;
 }
  
    length++;
  for(int i = length;i>index+1;i--){
        arr[i] = arr[i-1];
    }
    arr[index+1] = val;
    
}

int * manual_resizing(int * arr , int capacity, int size , int val){

    if(size == capacity){
        int * new_arr = new int[capacity*2];
        for(int i=0;i<capacity;i++){
            new_arr[i] = arr[i];
        }
        new_arr[capacity] = val;
        size++;
        delete []arr;
        return new_arr;
    }
  
 
    arr[size] = val;
    size++;
    return arr;

}



// Insert Elements at the end
int * Insert_elements_at_the_end(int * arr , int elements[], int capacity , int size , int number_of_elements){
if((number_of_elements + size) > capacity){

int * new_arr = new int[(capacity + number_of_elements)*2];

for(int i=0;i< size;i++){
    new_arr[i] = arr[i];
}



for(int i=size;i<size+number_of_elements;i++){
    new_arr[i] = elements[i-size];
}

size = size+number_of_elements;
delete [] arr;
return new_arr;
}



for(int i=size; i<size+number_of_elements ; i++){
    arr[i] = elements[i-size];
}

size = size+number_of_elements;
return arr;

} 




// insert elements at the beginning 
int * Insert_elements_at_the_beginning(int * arr , int elements[], int capacity , int &size , int number_of_elements){

    if((number_of_elements + size) > capacity){

int * new_arr = new int[(size + number_of_elements)*2];


for(int i = (number_of_elements+size-1); i >= number_of_elements; i--){
    new_arr[i] = arr[i-number_of_elements];
}

for(int i=0;i<number_of_elements;i++){
    new_arr[i] = elements[i];
}

size = size+number_of_elements;
delete [] arr;
return new_arr;
}




for(int i = (number_of_elements+size-1); i >= number_of_elements; i--){
    arr[i] = arr[i-number_of_elements];
}

for(int i= 0; i<number_of_elements ; i++){
    arr[i] = elements[i];
}

size = size+number_of_elements;
return arr;

} 

// it check the space is available if it is available then it place there if not so return false
bool enqueue(int arr[], int &front, int &rear ,int e , int& capacity ){
    if((rear+1)%capacity == front){
      return false;
    }
    
arr[rear] =e;
rear = (rear+1)%capacity;

return true;
}

bool dequeue(int arr[], int & front , int & rear, int &capacity){
     
    if(front == rear){
        return false;
    }
    
    
    front =(front+1)%capacity;
    return true;
}
int main(){
int arr[5] = {10, 20, 30 , 40 , 50};

// Manual resizing  it is not efficient in this case because old array can't be deleted until program
// confirm that new array size is greater than old array 
int new_arr[8];

for(int i=0;i<5;i++){
  new_arr[i] = arr[i];
}



}