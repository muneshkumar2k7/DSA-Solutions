#include <iostream>

using namespace std;


bool IsValid(vector <vector<int>> grid, int r, int c,int n , int exp_val){
if(r<0 || c<0 || c>=n || r>= n || grid[r][c] !=exp_val)
    return false;


if(exp_val == ((n*n)-1))
 return true;

bool ans1 = IsValid(grid, r-2,  c+1, n ,  exp_val+1);
bool ans2 = IsValid(grid, r-2,  c-1, n ,  exp_val+1);
bool ans3 = IsValid(grid, r+2,  c+1, n ,  exp_val+1);
bool ans4 = IsValid(grid, r+2,  c-1, n ,  exp_val+1);
bool ans5 = IsValid(grid, r-1,  c+2, n ,  exp_val+1);
bool ans6 = IsValid(grid, r-1,  c-2, n ,  exp_val+1);
bool ans7 = IsValid(grid, r+1,  c+2, n ,  exp_val+1);
bool ans8 = IsValid(grid, r+1,  c-2, n ,  exp_val+1);

return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}
int main(){
     return 0;
}