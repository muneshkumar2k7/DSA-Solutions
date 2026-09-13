#include <iostream>
using namespace std;
int fibb(int n){
    if(n <=1) return n;
    
    return fibb(n-1) + fibb(n-2);
}

// DP Basic two portion 
// Memoization(recursion)-> top down approach and Tabulation(iteration)-> bottom up approach

// Memoized DP and Memoization
int fibbDP(int n , vector<int> &arr){
    if(n <=1) return n;
    
    // if not available then calculate and return
   if(arr[n] == -1 ){
    arr[n] = fibbDP(n-1, arr) + fibbDP(n-2, arr);
    return arr[n];

   }else{
    // if available then only return
    return arr[n];
   }
}

int FibbTab(int n){
    vector <int> Fibbval(n+1, -1);
    Fibbval[0] = 0;
    Fibbval[1] = 1;

    int i = 2;
    while(i<= n){
      Fibbval[i] =  Fibbval[i-1] + Fibbval[i-2];
        i++;
    }
    return Fibbval[n];
}



// Climbing Stairs 
int Climbing_Stairs(int n , vector<int> & arr){
    if(n ==2 || n==1) return n;

    if(arr[n] != -1){
     return arr[n];
    }
     return arr[n] = Climbing_Stairs(n-1) + Climbing_Stairs(n-2);
}

int ClimbingStairs_tab(int n){
    if(n ==2 || n==1) return n;
 vector <int> ways(n+1);

   ways[1] =1;
   ways[2] =2;

   for(int i=3;i<=n;i++){
    ways[i]= ways[i-1]+ways[i-2];
   }
   
   return ways[n];
}

// House Robber
int HouseRobber(vector<int> nums, int houses){
    if(houses == 0 )
        return 0;
    
    if(houses == 1)
    return nums[houses - 1];

vector <int> sum(houses+1);

sum[0] = nums[0];
sum[1] = max(nums[0],nums[1]);

for(int i=2;i<houses;i++){
sum[i] = max(nums[i]+sum[i-2] , sum[i-1]);
}

return sum[houses-1];
}

// Circular House Robber
int HouseRobber_Circ(vector<int> nums, int houses){
    if(houses == 0 )
        return 0;
    
    if(houses == 1)
    return nums[houses - 1];
    
    if(houses == 2)
    return max(nums[0],nums[1]);

    vector<int> arr_one(houses-1);
    for(int i=0;i<houses-1;i++){
        arr_one[i] = nums[i+1];
    }

     vector<int> arr_two(houses-1);
    for(int i=0;i<houses-1;i++){
        arr_two[i] = nums[i];
    }

    int sum_one = HouseRobber(arr_one,houses-1);
    int sum_two = HouseRobber(arr_two,houses-1);

    return max(sum_one,sum_two);
}
int main(){

}