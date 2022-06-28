class Solution {
public:
    bool isValid(vector<vector<char>>&board,int row,int col,char num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num)return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==num)return false;
        }
        int startRow = row - row%3 ;
        int startCol = col - col%3 ;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+startRow][j+startCol]==num)return false;
            }
        }
        return true;
    }
    bool soduku(vector<vector<char>>&board,int row,int col){
        if(row==8 && col==9){
            return true;
        }
        if(col==9){
            row++;
            col = 0 ;
        }
        if(board[row][col]!='.')return soduku(board,row,col+1);
        for(int num=1 ; num<=9;num++){
            char charNum = (char)(num+'0');
            if(isValid(board,row,col,charNum)){
                board[row][col] = charNum;
                if(soduku(board,row,col+1)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        soduku(board,0,0);
    };
};