#include <iostream>
using namespace std;
#include <climits>
#include <queue>
#include<vector> 

int  max_sum(int arr[], int size , int k){

int left = 0;
int right = k-1;
int maximum = INT_MIN;
int sum = 0;

for(int i = left ;i<=right ;i++){
    sum +=arr[i];
}

while(right < size-1){
   
   sum -= arr[left];
   left++;
   
   right++;
   sum +=arr[right];
   

  if(sum > maximum ) maximum =sum;  
   
}

return maximum;

}


float avg_sum(int arr[], int size, int k){
if(k <= 0 || k > size) return 0;

int left = 0;
int right = k;
float total_sum = 0;
float sum = 0;
int n = size - k + 1;

for(int i=left ;i<right ;i++){
    sum += arr[i];
}
total_sum += sum;

while(right < size-1){

    sum -= arr[left];
    left++;

    right++;
    sum += arr[right];
   
    total_sum += sum;
}


return (total_sum/n);

}


int count_array_ones(int arr[], int size, int k){
if(k <= 0 || k > size) return 0;

int left = 0;
int right = k;
int count = 0;
int max_count = 0;


for(int i=left;i<right;i++){
    if(arr[i]) count++;
}
if(count > max_count) max_count = count;


while(right < size-1){
    
    if(arr[left]) count--;
    left++;

    right++;
    if(arr[right]) count++;

    if(count > max_count) max_count = count;

}
return max_count;
}





vector<int> find_first_neg_in_every_window(int arr[], int size , int k){
vector <int> negative;
queue <int> neg_elements;
int answer;
    if(k <= 0 || k > size) return negative;

    int left = 0;
    int right = k;
    

    for(int i=left;i<right;i++){
        if(arr[i] < 0){
         neg_elements.push(arr[i]);
        } 
    }

    if(neg_elements.empty())
     answer = 0;
    else
      answer = neg_elements.front();

    negative.push_back(answer);

    while(right < size-1){
 
        if(arr[left] < 0){
            neg_elements.pop();
        }
         left++;
         

         if(arr[right+1] < 0){
            neg_elements.push(arr[right+1]);
         }
         right++;

             if(neg_elements.empty())
              answer = 0;
             else
              answer = neg_elements.front();

            negative.push_back(answer);

    }

    return negative;
}



vector <int> max_in_every_win(int arr[], int size, int k){
int left = 0;
int right = k;
deque <int> elements;
vector <int> max_elements;


for(int i= left ; i<right ;i++){

 while(!elements.empty() && arr[i] > arr[elements.back()]){
   elements.pop_back();
 }
 elements.push_back(i);

}
max_elements.push_back(arr[elements.front()]);

while(right < size-1){
    
    left++;

    while (!elements.empty() && elements.front() < left) {
    elements.pop_front();
}
    

    while(!elements.empty() && arr[right+1] > arr[elements.back()]){
   elements.pop_back();
    }
 elements.push_back(right+1);

    right++;


    max_elements.push_back(arr[elements.front()]);
}

return max_elements;

};


vector<int>min_in_every_window(int arr[],int size, int k){
vector<int>minimum_elements;
deque<int> min_element;
int left = 0;
int right = k;

for(int i=left ;i<right ; i++){
    while(!min_element.empty() && arr[i] < arr[min_element.back()]){
        min_element.pop_back();
    }
    min_element.push_back(i);
}

minimum_elements.push_back(arr[min_element.front()]);


while(right < size-1){
  left++;

  while(!min_element.empty() && min_element.front() < left){
    min_element.pop_front();
  }

   while(!min_element.empty() && arr[right+1] < arr[min_element.back()]){
        min_element.pop_back();
    }
  right++;


  minimum_elements.push_back(arr[min_element.front()]);
}

return minimum_elements;

};






int main(){

    return 0;
}