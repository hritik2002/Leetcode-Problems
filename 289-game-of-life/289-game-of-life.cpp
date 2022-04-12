class Solution {
public:
    int checkLives(vector<vector<int>>&board,int i,int j){
        int tempI = i , tempJ = j ;
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        if(i-1>=0){
            if(board[i-1][j]==1)count++;
        }
        if(j-1>=0){
            if(board[i][j-1]==1)count++;
        }
        if(i-1>=0&&j-1>=0){
            if(board[i-1][j-1]==1)count++;
        }
        if(i+1<m){
            if(board[i+1][j]==1)count++;
        }
        if(j+1<n){
            if(board[i][j+1]==1)count++;
        }
        if(i+1<m&&j+1<n){
            if(board[i+1][j+1]==1)count++;
        }
        
        if(i+1<m && j-1>=0 ){
            if(board[i+1][j-1]==1)count++;
        }
        if(i-1>=0 && j+1<n){
            if(board[i-1][j+1]==1)count++;
        }
        
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>temp ;
        temp = board ;
        int m = board.size() , n = board[0].size();
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j < n ;j++){
                // check number of lives around
                int numOfLives = checkLives(board,i,j);
                if(numOfLives<2 || numOfLives>3){
                    temp[i][j]=0;
                }else if(numOfLives==3){
                    temp[i][j]=1;
                }
            }
        }
        board = temp ;
    }
};