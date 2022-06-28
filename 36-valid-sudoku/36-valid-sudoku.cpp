class Solution {
public:
    bool isValid(vector<vector<char>>&board,int row,int col,char num){
        for(int i=0;i<9;i++){
            if(col==i)continue;
            if(board[row][i]==num)return false;
        }
        for(int i=0;i<9;i++){
            if(row==i)continue;
            if(board[i][col]==num)return false;
        }
        int startRow = row - row%3 ;
        int startCol = col - col%3 ;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i+startRow==row && j+startCol==col)continue;
                if(board[i+startRow][j+startCol]==num)return false;
            }
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board,int row=0,int col=0) {
        if(row==8 && col==9)return true;
        if(col==9){
            row++;
            col=0;
        }
        if(board[row][col]=='.')return isValidSudoku(board,row,col+1);
        if(isValid(board,row,col,board[row][col]))return isValidSudoku(board,row,col+1);
        return false;
    }
};