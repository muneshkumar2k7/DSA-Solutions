#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> // for std::swap


// bubble sort
std::vector<int> sortArray(std::vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool Isswap = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                Isswap = true;
            }
        }
        
        // Fixed: Check 'Isswap' instead of 'swap'
        if (!Isswap) return nums; 
    } 

    return nums;      
}


// selection sort
void selectionSort(int arr[],int len){
for(int i=0;i<len-1;i++){
   int min_idx = i;

    // find minimum Index
for(int j=i+1;j<len;j++){
   if(arr[j] < arr[min_idx]) min_idx = j;
}

 // swap  minimum index and current index; 
 std::swap(arr[min_idx], arr[i]);
}
}



// insertion sort
void Insertion_sort(int arr[],int n ){
for(int i=1;i<n;i++){

int curr = arr[i];
int prev = i-1;

// loop shift till we find correct position 
while(prev >= 0 && arr[prev] > curr){
 arr[prev+1] = arr[prev];   
 prev--;
}

// insert current 
 arr[prev+1]=   curr;
}

}


void mergeSort(int arr[],int start , int end){
if(start  < end){

int mid = start + (end -start)/2;
// left
mergeSort(arr, start ,mid);
// right
mergeSort(arr,mid+1,end);

int i = start;
int j = mid+1;
vector <int> temp;

while(i <= mid && j <= end){
    if(arr[i] < arr[j]){
        temp.push_back(arr[i]);
        i++;
    }else{
        temp.push_back(arr[j]);
        j++;
    }
}

// Copy remaining Left parts
while(i <= mid){
temp.push_back(arr[i]);
i++;
}

// Copy remaining Right Parts
while(j <= end){
temp.push_back(arr[j]);
j++;
}

// Putting into Original Array
for(int idx = 0; idx<temp.size();idx++){
    arr[idx+start] = temp[idx];
}

}

};


// Partitioning 
int Partition(int arr[] , int start , int end){
    int pivot  = arr[end];
    int idx  = start - 1;

 for(int j=start ; j<=end;j++){
    if(arr[j] <= pivot){
        idx++;
        std::swap(arr[j],arr[idx]);
    }
 }

 return idx;
}

// Quick Sort
void QS(int arr[], int start , int end){

if(start < end){

int ind=Partition(arr, start,end);

// Left Half
QS(arr,start , ind-1);
// Right Half
QS(arr, ind+1 , end);

}

};


void counting_sort(int arr[], int range , int number_of_element){
    std::vector<int> temp(range + 1, 0);
    int n =0;
    for(int i=0;i<number_of_element ; i++){
        temp[arr[i]]++; 
    }

    for(int i=0;i<=range;i++){
       for(int j=0;j<temp[i];j++){
        arr[n] = i;
        n++;
       }
    }
    
}

// Shell Sort
void shell_sort(int arr[], int n){
    for(int gap = n/2;gap>=1 ; gap /=2){
        for(int i = gap ; i+gap < n ; i++){
         int temp = arr[i];
         int j = i;
          
         while(j >= gap && arr[j-gap] > temp){
            arr[j] = arr[j-gap];
            j -=gap;
         }
         arr[j] = temp;
        }
    }
}

// radix Sort 
int Get_Max(int arr[], int n){
      int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}
void radix_count_sort(int arr[], int n ,int exp){
    int output[n];
    int count[10] = {0};

    for(int i=0;i<n;i++){
        int digit = (arr[i]/exp)%10;
        count[digit]++;
    }

    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    for (int i = n - 1; i >= 0; i--) {
     int digit = (arr[i] / exp) % 10;
     output[count[digit]-1] = arr[i];
    count[digit]--;
    }
    
     for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
};


void Radix_Sort(int arr[], int n){
    int max = Get_Max(arr,n);

for(int exp = 1 ; max/exp > 0 ; exp*=10){
   radix_count_sort(arr,n,exp);
}    
}

int main(){

};