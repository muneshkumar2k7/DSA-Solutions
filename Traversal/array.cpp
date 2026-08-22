#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5,6};
   int length = sizeof(arr)/sizeof(arr[0]);
// Forward Traversal
for(int i=0;i<length-1 ; i++){
    cout<< arr[i] <<endl;
}
   
// Reverse Traversal
for(int i=length-1;i>=0 ; i--){
    cout<< arr[i] <<endl;
}

// Range Based Traversal
for (int x : arr) {
    cout << x << " ";
}

// Index-Based Traveral 
for (int i = 0; i < 5; i++) {
    cout << "Index = " << i
         << " Value = " << arr[i] << endl;
}

// Two Pointer traversal
int left = 0;
int right = length-1;

while(left <= right){
  cout << arr[left] << " ,"  << arr[right] << endl;

  left++;
  right--;
}



// Sliding window Traversal 

int win_size = 2;
// length - win_size +1  ===> 6 - 2 +1 = 5

for(int i=0; i< length - win_size +1 ; i++ ){
    cout<<"{";

    for(int j =i ; j < i + win_size ; j++){
  
   cout <<arr[j] ;   
    }

    cout<< "}" <<endl;
}



// Prefix traveral  

int prefix[6];
prefix[0] = arr[0];

 cout << prefix[0] << ", ";

for(int i=1;i<length;i++){

  prefix[i]= prefix[i-1]+ arr[i];
  cout << prefix[i] << ", ";
}


// Suffix traveral  
int suffix[6];

suffix[5]=arr[5];
cout << endl;
 cout << suffix[5] << ", ";
for(int i=length-2 ;i >=0;i--){
    suffix[i] = suffix[i+1] + arr[i];
 cout << suffix[i] << ", ";
}

// Conditional Traversal 
cout<<endl;
for(int i=0;i<length;i++)
{
    if(arr[i]%2==0)
        cout<<arr[i]<<" ";
}



// Zig zag traversal also called two pointer traversal

for(int i=0;i<6;i+=2)
{
    cout<<arr[i]<<" ";
}

// Circular traversal 
// Use modulo for circular traversal



for(int i=0;i<15;i++){
    cout << arr[i%3] ;

    if(i%3 == 2){
        cout <<endl;
    }
}


    return 0;
}


