#include <iostream> 
using namespace std;

bool IsSafe(vector<vector<char>>&board , int row ,int col , char val){

    for(int i=0;i<9;i++){
     if(board[row][i] == val) return false;
    }

    
    for(int i=0;i<9;i++){
       if(board[i][col] == val) return false;  
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3; 

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[startRow+i][startCol+j] == val) return false;
        }
    }

    return true;
}

bool SS(vector<vector<char>>&board , int row ,int col){
    if(row == 9){
         return true;
    }


    if(col == 9) {
    return SS(board, row + 1, 0);
    }

    if(board[row][col] != '.'){
        
      return SS(board,row,col+1);
    }
    for(int val = 1; val<10;val++){
 if(IsSafe(board , row , col , '0' + val)){
        board[row][col] = '0' + val;

       if(SS(board,row,col+1)) return true;

        board[row][col] = '.';
    }

    }
   

    return false;

}
int main(){
    return 0;
}