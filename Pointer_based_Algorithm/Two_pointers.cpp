#include <iostream>
#include <vector>

using namespace std;

vector<int>two_sum(int arr[], int left , int r, int target){
   vector <int> elements;
    while(L < R){
       int sum = arr[left]+ arr[right];
     
       if(sum == target) {
        elements.push_back(arr[left]);
        elements.push_back(arr[right]);
    }

      if(sum < target){
         left++;
      }else{
         right--;
      } 
    }
      
    return elements;
}


bool valid_palindrome(string name,int l, int r){

   while(l< r){
      if(name[l] != name[r]) return false;
      l++;
      r--;
   }
   return true;

}

void Reverse_string(string s, int left , int right){

    while(left< right){
      if(s[left] != s[right]){
         swap(s[left], s[right]);
      }
      left++;
      right--;
   }

}

vector<int> Squares_of_sorted_Array(int arr[], int l , int r){
   int  pos = r;
   vector<int>result(r + 1);
   while(l<=r){

      if(abs(arr[l])  < abs(arr[r])){
        result[pos] = arr[r]*arr[r];
        r--;
     
      }else{
       result[pos] = arr[l]*arr[l];
       l++;
       
      }
      pos--;
   }

   return result;
}

int  container_with_most_water(int arr[],int l, int r){
   int max_area = 0;
   while(l < r){
      int width = r - l;
      int height = min(arr[l] , arr[r]);

      int area = width*height;
      if(area > max_area){
         max_area = area;
       }

      if(arr[l] < arr[r]){
         l++;
      }else{
         r--;
      }
   }
   return max_area;

}

vector<vector<int>> tripletSum(int arr[], int size){
int sum = 0;
vector <int>triplet;
vector<vector<int>> res;


sort(arr, arr+size);


for(int i=0;i<size-2;i++){
   if(i > 0 && arr[i] == arr[i-1])
    continue;

   l = i+1;
   r = size - 1;
while(l < r){
      
sum = arr[i] + arr[l] + arr[r];

if(sum == 0){
   triplet.push_back(l);
   triplet.push_back(r);
   triplet.push_back(i);
   res.push_back(triplet);
   triplet.clear();

   l++;
   r--;
}

if(sum > 0){
  r--;
}
if(sum <0){
   l++;
}
}
}
}

vector<vector<int>> quadrapletSum(int arr[], int target , int size){

vector <int>quadraplet;
vector<vector<int>> res;
int l, r;

sort(arr,arr+size);
for(int i = 0;i < size-3;i++){
   if(i > 0 && arr[i] == arr[i-1])
    continue;

   for(int j=i+1;j<size-2;j++){
     l = j+1;
     r = size-1;

     while(l < r){
      int sum = arr[l]+arr[r] + arr[i] + arr[j];

      if(sum == target){
         quadraplet.push_back(arr[r]);
         quadraplet.push_back(arr[l]);
         quadraplet.push_back(arr[i]);
         quadraplet.push_back(arr[j]);
         res.push_back(quadraplet);
         quadraplet.clear();
         l++;
         r--;
      }

      if(sum > target){
        r--;
      }

      if(sum < target){
       l++;
      }
     }

   }
}
return res;
}



int rain_trap(int arr[], int size){
   int left =0;
   int right = size-1;
   int trap = 0;
   int left_max = arr[0];
   int right_max =arr[size-1];

   
    while(left < right){
    
    if(arr[left] <= arr[right]){

      if(arr[left]> left_max)
        left_max = arr[left];
      else
         trap+= left_max - arr[left];

       left++;  
    }else{

      if(arr[right] > right_max)
        right_max = arr[right];
      else
        trap += right_max - arr[right];

      right--;
    }
     
   }
   
 return trap;  

}

int main(){

}