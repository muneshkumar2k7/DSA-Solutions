#include <iostream>
using namespace std;
#include <climits>
// target , arr, size 
// vector
// left ++ shrink .............. right++ expand
int min_subarray_length(int arr[], int size, int target){
    int left = 0;
    int right = 0;
    int min_len = INT_MAX;
    int len =0;
    int sum = 0;
 

    while(right < size){
         

         while(sum >= target){
            if(len < min_len){
                min_len = len;
            }
            sum -= arr[left];
            len--;
           left++;
           
        }

        if(sum < target){
            sum += arr[right];
            len++;
            right++;
           
        }

       
    }

    return min_len;
}



vector<vector<int>> all_min_subarray(int arr[], int size, int target){
    int left = 0;
    int right = 0;
    int sum = 0;
    vector<vector <int>> final;
    vector<int> temp;     

    while(1){
   

         while(sum >= target){

            final.push_back(temp);
            sum -= arr[left];
            left++;
            // erase first element
            temp.erase(temp.begin());
           
        }

     if(right >=size) break;

        if(sum < target){
            sum += arr[right];
            temp.push_back(arr[right]);
            right++;   
        }


    }

    return final;
}



vector<int> min_subarray(int arr[], int size, int target){
    int left = 0;
    int right = 0;
    int sum = 0;
    vector <int>final ;
    int min_len =INT_MAX;
    vector<int> temp;     

    while(true){

         while(sum >= target){
            
           if((right-left) < min_len){
            min_len = right-left;
            final = temp;
           }

            sum -= arr[left];
            left++;
            // erase first element
            temp.erase(temp.begin());
        }
      
        if(right >= size) break;

        if(sum < target){
            sum += arr[right];
            temp.push_back(arr[right]);
            right++;  
        }

    }

    return final;
}



deque<int> longest_subarray(int arr[], int size, int target){
    int left = 0;
    int right = 0;
    int sum = 0;
    deque<int>final;
    int max_len =0;
    deque<int> temp;  

    while(true){
        
        while(right < size && arr[right]+ sum <= target ){
        sum += arr[right];
        temp.push_back(arr[right]);
        right++;
        }
       
         
        
        if(right - left > max_len){
          max_len = right - left;
          final = temp;          
        } 

        if(right >= size) break;

            sum -= arr[left];
            temp.pop_front();
            left++;    

    }

    return final;
}



string longest_substr(string s , int len){
    
}
int main(){
    
}