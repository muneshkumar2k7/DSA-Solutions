// 0/1 Knapsack by dp -> only recursion
double Knapsack_DP(pair<double,int> bag[]  ,int W , int n ){
 if(W ==0 || n==0){
    return 0;
 }
  

 if(bag[n-1].second <= W){
    double inc = bag[n-1].first + Knapsack_DP(bag ,W-bag[n-1].second , n-1);
    double exc = Knapsack_DP(bag,W,n-1);

    return max(inc , exc);
 }else{
    return Knapsack_DP(bag,W,n-1);
 }
}

// Memoization
double Knapsack_DP_memo(pair<double,int> bag[]  ,int W , int n  , vector<vector<int>> &value){
 if(W ==0 || n==0){
    return 0;
 }
  

 if(bag[n-1].second <= W){

    if(value[n-1][W] != -1){return value[n-1][W];}
    
       double inc = bag[n-1].first + Knapsack_DP_memo(bag ,W-bag[n-1].second , n-1 , value);
    double exc = Knapsack_DP_memo(bag,W,n-1 , value);

    value[n-1][W] = max(inc , exc);
    return value[n-1][W];
    
 

 }else{

if(value[n-1][W] != -1){
    return value[n-1][W];
}

value[n-1][W] = Knapsack_DP_memo(bag,W,n-1, value);
return value[n-1][W];

 }
}


// Tabulation
double Knapsack_DP_Tabulation(pair<double,int> bag[], int W, int n){
     vector<vector<double>> dp(n + 1, vector<double>(W + 1, 0));

     for(int i=1;i<=n ;i++){
        for(int w = 1; w<=W;w++){

            if(bag[i-1].second <= w){
              double inc =  bag[i-1].first + dp[i-1][w - bag[i-1].second];
              double exc = dp[i-1][w];
              
             dp[i][w] =  max(inc,exc);
            }else{
                 dp[i][w] = dp[i-1][w];
            }

        }
     }

     return dp[n][w];
}

// LIS Brute Force approach
// Find all increasing subsequences then find out max length


int LIS_Brute_Force(int arr[], int n,int index, int prev){

    if(index == n){
        return 0;
    }
    

    int exc = LIS_Brute_Force(arr , n,index+1, prev);
    int inc = 0;

    if(prev == -1 || arr[prev] < arr[index]){
    inc = 1 + LIS_Brute_Force(arr , n, index+1, index);
    }
    
    return max(inc,exc);    
}


// DP 
int LIS_DP(int arr[], int n , int index , int prev , vector<vector<int>> &dp){
    
    if(index == n){
        return 0;
    }

   if(dp[index][prev+1] != -1){
    return dp[index][prev+1];
   }
    

    int exc = LIS_DP(arr , n,index+1, prev , dp);

    int inc = 0;

    if(prev == -1 || arr[prev] < arr[index]){
    inc = 1+ LIS_DP(arr, n, index+1 , index , dp);
    }

    dp[index][prev+1] = max(inc,exc);
    return  dp[index][prev+1];
   
}

// Brute Force 
int LCS(string a , string b, int i, int j){
 if(i == a.length() || j == b.length()){
        return 0;
    }

if(a[i] == b[j]){
     return 1+LCS(a,b,i+1,j+1);
}else{
   int first = LCS(a,b,i+1,j);
   int second = LCS(a,b,i,j+1);
   return max(first,second);
}
    
}


// DP 
int LCS(string a , string b, int i, int j , vector<vector<int>> &dp){
 if(i == a.length() || j == b.length()){
        return 0;
    }

   if(dp[i][j] != -1){
     return dp[i][j];
    }


   if(a[i] == b[j]){
     dp[i][j]=  1+LCS(a,b,i+1,j+1 , dp);
     return dp[i][j];
 }else{
   int first = LCS(a,b,i+1,j,dp);
   int second = LCS(a,b,i,j+1 , dp);
   dp[i][j] =  max(first,second);
   return dp[i][j];
}
}

// Matrix Chain Multiplication (recursive)
int MCM_solve(int arr[], int i , int j){
int a,b,min_cost;

min_cost =MAX_INT;
   if(i >= j){
   return 0;
 }

 for(int k= i ; k <= j-1 ; k++){
    a  = MCM_solvesolve(arr,i,k);
    b = MCM_solves(arr,k+1,j);

if(a+b + arr[i-1]*arr[k]*arr[j] < min_cost){
   min_cost = a+b + arr[i-1]*arr[k]*arr[j];
}
 }
return min_cost;

}

// DP Memoization 
// Matrix Chain Multiplication (recursive)
int MCM_solve_DP(int arr[], int i , int j , int ** store){
int a,b, cost,  min_cost;



min_cost =MAX_INT;
   if(i >= j){
   return 0;
 }

 if(store[i][j] != -1){
    return store[i][j];
}

 for(int k= i ; k <= j-1 ; k++){

   if(store[i][k] == -1){
    store[i][k] = MCM_solve_DP(arr,i,k,store);
   }
   a=store[i][k];


   if(store[k+1][j] == -1){
     store[k+1][j] = MCM_solve_DP(arr,k+1,j,store);
   } 
   b= store[k+1][j];

  
   cost =  arr[i-1]*arr[k]*arr[j] + a+b;
   
   
if(cost < min_cost ){
   min_cost = cost;
}

 }
 

   store[i][j] = min_cost;


return store[i][j];

}

bool isPalindrome(string s, int i, int j) {

    while(i < j) {

        if(s[i] != s[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}
/*
i        j
n  i t i n 
a  b a b
*/

// Palindrome Partitioning
int Palindrome_Partitioning(string s , int i , int j){
   int a , b , min_part;
   min_part = MAX_INT;
   if(i>=j){
      return 0;
   }
   
   if(isPalindrome(s,i,j)){
      return 0;
   }

   for(int k = i; k<j ; k++){
      
   a = Palindrome_Partitioning(s,i,k);
   b = Palindrome_Partitioning(s,k+1, j);

   int  part = 1 + a + b ;

   if(part < min_part){
      min_part = part;
   }
   
   }

   return min_part;
}

// DP memoization of Palindrome Partitioning
int  PP_DP(string s , int i , int j , int ** store){
   int a , b , min_part;
   min_part = MAX_INT;
   if(i>=j){
      return 0;
   }
   
   if(isPalindrome(s,i,j)){
      return 0;
   }

   if(store[i][j] != -1){
      return store[i][j];
   }

   for(int k = i; k<j ; k++){
   if(store[i][k] == -1){
     store[i][k] = PP_DP(s,i,k,store);
   }   
   a  = store[i][k];


   if(store[k+1][j] == -1){
     store[k+1][j] = PP_DP(s,k+1, j,store);
   }   
   b = store[k+1][j];
   
   int  part = 1 + a + b ;

   if(part < min_part){
      min_part = part;
   }
   
   }


 
   store[i][j] = min_part;

   return store[i][j];
}
