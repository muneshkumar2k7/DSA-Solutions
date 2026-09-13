#include <iostream> 
#include <vector>
using namespace std;

// Basic Recursions 
int fibb(int n){
if(n == 0 || n ==1)
    return n;

    
return fibb(n-1) + fibb(n-2);

};

bool Is_Sorted(int arr[], int n){
if(n <= 1){
    return true;
}


if(arr[n-1] >= arr[n-2]){
   return Is_Sorted(arr,  n-1);
}else{
    return false;
}
     
}

// Print all Subsets
void all_Subsets(vector <int > & Sets , vector <int> &subset ,vector <vector<int>> &power_set , int i, int length){

if(i == length){
    power_set.push_back(subset);
    return ;
}

// first include element in the set and recursively call
subset.push_back(Sets[i]);
all_Subsets(Sets,subset,power_set,i+1,length);

subset.pop_back();
// next step exclude the element in the set and recursively call
all_Subsets(Sets,subset,power_set,i+1,length);

}

// Print All Subsets without duplicate when array has duplicate numbers 
// first sort the array or array should be sorted

void all_DupSub(vector <int > & Sets , vector <int> &subset ,vector <vector<int>> &power_set , int i, int length){

if(i == length){
    power_set.push_back(subset);
    return ;
}

// first include element in the set and recursively call
subset.push_back(Sets[i]);
all_DupSub(Sets,subset,power_set,i+1,length);


subset.pop_back();

// Skip all duplicate elements (with bounds check)
    int idx = i + 1;
    while (idx < length && Sets[idx] == Sets[i]) {
        idx++;
    };

// next step exclude the element in the set and recursively call
all_DupSub(Sets,subset,power_set,idx,length);

}



// Combination 
void Combination(vector <int> &set,vector <int> &subset, vector <vector<int>> &combined_set, int i ,int k , int length ){

if(subset.size() == k){
    combined_set.push_back(subset);
    return;
}

if(i == length) return;


// first include element in the set and recursively call
subset.push_back(set[i]);
Combination(set,subset,combined_set,i+1,k,length);


subset.pop_back();

// next step exclude the element in the set and recursively call
Combination(set,subset,combined_set,i+1,k,length);
};


void CombSum(vector <int> arr, int ind , vector<int> &combine, vector<vector<int>> &ans, int tar){
if(tar <0 || ind == arr.size()) return;

if(tar == 0){
    ans.push_back(combine);
    return;
}

// Take
    combine.push_back(arr[ind]);
    CombSum(arr, ind, combine, ans, tar - arr[ind]);
    combine.pop_back();

// Not take
CombSum( arr,  ind+1 , combine, ans,tar);

}

void swap(int &a, int &b){
     int temp;

     temp =a;
     a = b;
     b= temp;
};

// in basic array format
void Arr_permutations(int arr[],int ind , int len, int ** ans , int num_perm){
if(ind == len){
   for(int i =0;i<len;i++){
    ans[num_perm][i] = arr[i];
   }                        // base case
   num_perm++;
  return;
}

for(int idx= ind ; idx < len ;idx++){
  swap(arr[idx] , arr[ind]);
  Arr_permutations(arr,ind+1 ,len,ans,num_perm);
  swap(arr[idx] , arr[ind]);  // undo
}
}


// in vector format
void permutations(vector<int>arr, int ind , int len, vector<vector<int>> &ans){
if(ind == len){
  ans.push_back(arr);
  return;
}

for(int idx= ind ; idx < len ;idx++){
  swap(arr[idx] , arr[ind]);
  permutations(arr,ind+1 ,len,ans);
  swap(arr[idx] , arr[ind]);  // undo
}
}



// Rat Maze
void GetAns(vector<vector<int>> mat, int r , int c , string path , vector<string> &ans,int n , vector<vector<bool>> &vis){
  if(r < 0 || c < 0 || r >= n || c >= n) return;
   if(mat[r][c] == 0 || vis[r][c]) return;
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

vis[r][c] = true;
    GetAns(mat, r+1, c , path +"D",ans ,n , vis);
    GetAns(mat, r-1, c , path +"U",ans,n, vis);
    GetAns(mat, r, c-1 , path +"L",ans, n, vis);
    GetAns(mat, r, c+1 , path +"R",ans, n , vis);
vis[r][c] = false; 
}

bool Issafe(vector<string>& board , int row , int col , int n){
 
    for(int i=0;i<n;i++){
        if(board[row][i] =='Q') return false;
    }

    for(int i=0;i<n;i++){
        if(board[i][col] =='Q') return false;
    }

    for(int i=row,j=col ; i>=0 && j>=0;i--,j--){
     if(board[i][j] =='Q') return false;
    }

    for(int i=row,j=col ; i>=0 && j<n;i--,j++){
        if(board[i][j] =='Q') return false;
    }

    return true;
}

// NQueens

void NQueens(vector<string> &board , int row , int n , vector<vector<string>> &ans ){
if(row == n){
  ans.push_back(board);
    return;
}

    for(int j=0;j<n;j++){
    if(Issafe(board , row,j,n)){
      board[row][j] ='Q';
      NQueens(board , row+1 , n, ans);
      board[row][j] = '.';
    }
    }


}
int main(){
    return 0;
}