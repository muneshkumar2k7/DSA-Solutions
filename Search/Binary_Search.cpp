#include <iostream>
using namespace std;
#include <iterator>
#include <climits>
#include <cmath>
int neg_inf = INT_MIN;
int pos_inf = INT_MAX;

// isSorted
// 1 2 3 
// 3 2 1 
bool Is_Sorted(int arr[] , int start , int end){
    int Is_Asc = true;
    int Is_Des = true;
    
for(int i = start; i<end ; i++){
  if(arr[i] > arr[i+1]) Is_Asc = false;
}

for(int i = start; i<end ; i++){
  if(arr[i] < arr[i+1]) Is_Des = false;
}

return Is_Asc || Is_Des;
}

// Recusive BS
int BS(int sorted[], int start , int end , int val){
if(start > end) return -1;

int mid = start + (end-start)/2;

if(val == sorted[mid]) return mid;

if(val > sorted[mid]){
 start = mid+1;
 return BS(sorted, start ,  end ,  val);
}else{
    end = mid-1;
return BS(sorted,  start ,  end , val);
}

}


// Iterative BS

int BS(int sorted[], int start , int end , int val){

    while (start <= end)
    {
        
     int mid = start + (end-start)/2;

        if(val == sorted[mid]) return mid;

        if(val > sorted[mid])
          start = mid+1;

        if(val < sorted[mid]) 
          end = mid-1;
    }

    return -1;

}




// First Occurence 
int BS_FO(int sorted[], int start , int end , int val , int &store){

if(start > end ){
    if(store!=-1)
      return store;
    else 
      return -1;
}



int mid = start + (end-start)/2;

if(val == sorted[mid]) {
    store = mid;
    end  = mid-1;
return BS_FO(sorted, start ,  end ,  val ,store );
};

if(val > sorted[mid]){
 start = mid+1;
 return BS_FO(sorted, start ,  end ,  val ,store );
}else{
    end = mid-1;
return BS_FO(sorted,  start ,  end , val , store);
}

}



// Last Occurence 
int BS_LO(int sorted[], int start , int end , int val , int &store){

if(start > end ){
    if(store!=-1)
      return store;
    else 
      return -1;
}



int mid = start + (end-start)/2;

if(val == sorted[mid]) {
    store = mid;
    start  = mid+1;
return BS_LO(sorted, start ,  end ,  val ,store);
};

if(val > sorted[mid]){
 start = mid+1;
 return BS_LO(sorted, start ,  end ,  val ,store);
}else{
    end = mid-1;
return BS_LO(sorted,  start ,  end , val , store);
}

}


int lower_bound_BS(int sorted[] , int start , int end , int val , int &store ){
if(start > end ){
    if(store!=-1)
      return store;
    else 
      return -1;
}



int mid = start + (end-start)/2;



if(val > sorted[mid]){
 start = mid+1;
 return lower_bound_BS(sorted, start ,  end ,  val , store);
}else{
   store = mid;
   end  = mid -1;
   return lower_bound_BS(sorted, start ,  end ,  val , store);
}

}

int upper_bound_BS(int sorted[] , int start , int end , int val , int &store ){
if(start > end ){
    if(store!=-1)
      return store;
    else 
      return -1;
}



int mid = start + (end-start)/2;



if(val >= sorted[mid]){
 start = mid+1;
 return upper_bound_BS(sorted, start ,  end ,  val , store);
}else{
   store = mid;
   end  = mid -1;
   return upper_bound_BS(sorted, start ,  end ,  val , store);
}

}

int Frequency_and_range_BS(int sorted[] , int start , int end , int val , int &f , int &l , int freq){
if(start > end ){
      return freq;
}


int mid = start + (end-start)/2;

if(val == sorted[mid]){ 
    freq++;
int i =1;
int j= 1;

while( (mid+i) <= end && val == sorted[mid+i] ){
    freq++;
i++;
}

while( (mid-j) >= start && val == sorted[mid-j] ){
    freq++;
j++;
}
l = (mid+i)-1;
f = (mid-j)+1;

return freq;

}

if(val > sorted[mid]){
 start = mid+1;
 return Frequency_and_range_BS(sorted, start ,  end ,  val,f , l ,  freq);
}else{
    end = mid-1;
return Frequency_and_range_BS(sorted,  start ,  end , val,f, l , freq);
}

}


int freq_LB_UB(int sorted[], int start , int end, int val){
int num = -1;
int ind = -1;
    int ub=  upper_bound_BS(sorted, start,end,val, num );
   int lb=  lower_bound_BS(sorted,start,end, val ,ind);

   return ub-lb;
}



int RSA(int rotated_sort[],int start, int end , int value){
if(start > end) return -1;

int mid = start + (end-start)/2;

if(rotated_sort[mid] == value) return mid;

bool right= Is_Sorted(rotated_sort,mid,end);
bool left = Is_Sorted(rotated_sort,start,mid);

if(left){

if( rotated_sort[start] <= value && value<= rotated_sort[mid]){
return  RSA(rotated_sort , start , mid-1 , value);
}else{
return RSA(rotated_sort , mid+1 , end , value);
}

}else{

    if(right && rotated_sort[mid] <= value && value <= rotated_sort[end]){
return RSA(rotated_sort , mid+1 , end , value);
}else{
    return  RSA(rotated_sort , start , mid-1 , value);
}

}


}


// minimum search in rotated array

int Min_RSA(int sorted[], int start , int end ){
if(start == end)
    return start;

int mid = start + (end-start)/2;


if(sorted[mid]> sorted[end]){
return Min_RSA(sorted , mid+1, end);
}else{
return Min_RSA(sorted , start , mid);
}


}

// 4 5 6 7 0 1 2 
// Peak index in mountain

int Peak_ind(int sorted[], int start , int end){

while (start < end)
{
int mid = start + (end-start)/2;
if(sorted[mid] < sorted[mid+1])
    start = mid+1;
else 
   end = mid;

}


   return start; 
}

// Right Rotation count
int RRC(int sorted[], int start , int end){
 int n = Min_RSA(sorted, start , end );
 return n;
}

int LRC(int sorted[], int start , int end){
int n = Min_RSA(sorted, start , end );
return (end-n)+1;
}




// it is also Minimum Feasible
int First_true(bool arr[] , int start , int end ){
if(start == end) return start;
   
    int mid = start + (end-start)/2;


  if(arr[mid]){
   end = mid;
    return First_true(arr , start ,  end );
  }else{
    start = mid+1;
  return First_true(arr , start ,  end );
  }  
}

// it is also Maximum Feasible 
int Last_true(bool arr[] , int start , int end){

  if(start == end) return start;

  int mid = start + (end-start+1)/2;

   if(arr[mid]){
   start = mid;
    return Last_true(arr , start ,  end );
  }else{
    end = mid-1;
  return Last_true(arr , start ,  end );
  }  

}

int sqrt(int start , int end , int val){
    if (start == end)
        return start;


int mid = start + (end-start+1)/2;


    if (mid * mid <= val)
        return sqrt(mid, end, val);
    else
        return sqrt(start, mid - 1, val);

}
int sum_of_arr(int arr[] , int len){
  int sum = 0;
for(int i=0;i<len;i++){
sum+=arr[i];
}
return sum;
}

bool isValid(int mid , int arr[] , int len , int students){
  bool available = false;
  int sum = 0;
   int studentsUsed = 1;

 

  for(int i=0;i<len;i++){
   if(sum + arr[i] <= mid) {
    sum += arr[i];
}else{
 studentsUsed++;
   sum = arr[i];
}


  }
  

 return studentsUsed <= students; 
}


bool KOKO_valid(int mid , int arr[] , int len , int hours){
int h =0;
    for(int i=0;i<len;i++){
      h += ceil(arr[i]/float(mid));
     }

     return  h <= hours;

}



int Book_allocation(int books[],int minPage , int maxPage, int num_of_books , int students , int& ans){
  if(students > num_of_books) return -1;
  if(minPage > maxPage) return ans; 

  int mid = minPage + (maxPage-minPage)/2;

  if(isValid(mid ,books, num_of_books , students)){
   ans = mid;
   maxPage = mid-1;
   
  return Book_allocation(books,minPage , maxPage,num_of_books , students, ans);
  

  }else{
        minPage = mid+1;
  return Book_allocation(books,minPage , maxPage,num_of_books , students, ans); 
  }
};



bool Valid_time(int mid, int board_time[], int num_of_board, int painters){
int number_of_painters = 1;
int sum = 0;


for(int i=0;i<num_of_board;i++){
  if(sum + board_time[i] <= mid ){
    sum += board_time[i];
  }else{
    number_of_painters++;
    sum = board_time[i];
  }
}

return number_of_painters <=painters;

};


// painter partition's
int Painters_partition(int boards_time[] , int min,int max, int num_of_board, int painters ,int &ans){
if(painters > num_of_board) return -1;
if(min > max) return ans;

int mid = min + (max-min)/2;

if(Valid_time(mid,boards_time,num_of_board,painters)){
ans = mid;
max = mid-1;
return Painters_partition(boards_time, min,max, num_of_board,  painters ,ans);
}else{
  min = mid+1;
return Painters_partition(boards_time, min,max, num_of_board,  painters ,ans);
}
};

int find_max(int arr[], int len){
  int max_ind = 0;
for(int i=0;i<len;i++)
if(arr[i] > arr[max_ind]) max_ind = i;


return max_ind;
}

int find_min(int arr[], int len){
    int min_ind = 0;

    for(int i = 1; i < len; i++){
        if(arr[i] < arr[min_ind])
            min_ind = i;
    }

    return min_ind;
}



bool check_valid(int mid , int arr[] , int len , int number_of_cows){
int cows = 1; 
int diff= arr[0];

for(int i=0;i<len;i++){
if(arr[i] - diff >= mid){
  cows++;
  diff = arr[i];
}
}


return cows >= number_of_cows;
};

// Aggressive Cows 
int Min_Cows(int stalls[] ,int number_of_stalls , int min , int max,  int number_of_cows, int &ans){
if(number_of_cows > number_of_stalls || number_of_cows == 1) return -1;
if(min > max) return ans;
int mid = min + (max-min)/2;

if(check_valid(mid, stalls, number_of_stalls,number_of_cows)){
  ans = mid;
  min = mid+1;
  return Min_Cows(stalls,number_of_stalls,min,max,number_of_cows,ans);
}else{
  max = mid-1;
  return Min_Cows(stalls,number_of_stalls, min , max, number_of_cows,ans);
}

};


// Split array Largest 
int largest_sum(int arr[],int len,int min , int max, int k ,int ans){
if(k > len) return -1;
if(min > max) return ans;
  int mid = min + (max-min)/2;

  if(isValid(mid , arr , len,k)){
   ans = mid;
   max = mid-1;
   return largest_sum(arr, len , min , max , k, ans);
  }else{
    min = mid+1;
    return  largest_sum(arr, len , min , max , k, ans);
  }
};


// Koko
int Koko_bananas(int piles[] , int number_of_box , int min , int max , int hours , int ans){
if(min > max) return ans;
  int mid = min + (max-min)/2;

 if(KOKO_valid(mid , piles , number_of_box,hours)){
   ans = mid;
   max = mid-1;
   return Koko_bananas(piles,  number_of_box , min,max , hours, ans);
  }else{
    min = mid+1;
    return  Koko_bananas(piles, number_of_box , min , max , hours, ans);
  }  
}

// Ship Packages
int ship_packages(int packages[], int min , int max,int num_packs ,int days , int &ans){

   if(days > num_packs) return -1;
  if(min > max) return ans; 

  int mid = min + (max-min)/2;

  if(isValid(mid ,packages, num_packs , days)){
   ans = mid;
   max = mid-1;
   
  return ship_packages(packages,min , max,num_packs , days, ans);
  

  }else{
        min = mid+1;
    return ship_packages(packages,min , max,num_packs , days, ans);
  }
}



int matrix_bs(int **matrix , int row , int column , int target){
  for(int i=0;i<row;i++){
 int n = BS(matrix[i], 0 , column-1 , target);
 if(n != -1) return i+1;
  }

  return -1;
 
}
struct Position {
    int row;
    int col;
};

Position TD_Matrix_BS(int **matrix ,int start_row ,int end_row, int start_col , int end_col ,int tar ){
 Position p1;
 p1.row = -1;
 p1.col = -1;

for (int i = start_row; i <= end_row; i++)
{
  if(matrix[i][start_col] <= tar  && tar <= matrix[i][end_col]  ){
    p1.col = BS(matrix[i],start_col,end_col,tar);
        if(p1.col != -1)
         p1.row = i;
  }
}
return p1;

}
int MIN_Count(int **arr, int row ,int col, int num){
  int count = 0;

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
    if(arr[i][j] <= num){
      count++;
    }
  }
  }
  return count;
}


// high =11 low =1 ; mid =6  med =4 count 4   high =11 low = 6 mid =9 
// Matrix Median 
int Med_BS(int **arr , int row , int col ,int low , int high){
  if(high == low) return low;
int median = (row*col)/2 ;
  int mid = low + (high-low)/2;

int count =MIN_Count(arr, row , col, mid);


if(count > median){
  high = mid;
  return Med_BS(arr, row , col , low , high);
}else{
  low = mid+1;
  return Med_BS(arr, row , col , low , high);
}


}


// Kth smallest Element
int K_small(int **arr , int row , int col ,int low , int high ,int k){
  if(high == low) return low;
int mid =  low + (high-low)/2;
int count =MIN_Count(arr, row , col, mid);

if(count < k){
low = mid+1;
 return K_small(arr, row , col , low , high,k);
}else{
high = mid;
 return K_small(arr, row , col , low , high,k);
}

};

// assume tar = 2 and s = 1 and e = 2;
int Eqn_or_float_BS(int s, int e , int tar){
if(s> e) return -1;

int x = s+(e-s)/2;

if((x*x)-2< 0.01 && (-0.01) < (x*x-2))  return x;

if((x*x)> 2){
    e = x;
   return  Eqn_or_float_BS( s,  e ,  tar);
}else{
  s = x;
  return Eqn_or_float_BS( s,  e ,  tar);
}

}


int main(){
return 0;
}