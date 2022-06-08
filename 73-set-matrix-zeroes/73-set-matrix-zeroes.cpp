class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0 ; i<matrix.size();i++){
            for(int j=0 ; j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    int row = i , col = j ;
                    ans[i][j] = matrix[i][j];
                    while(row--){
                        ans[row][col] = 0 ;
                    }
                    row = i;
                    while(row<matrix.size()){
                        ans[row++][col] = 0 ;
                    }
                    row = i ;
                    while(col--){
                        ans[row][col] = 0;
                    }
                    col = j;
                    while(col<matrix[0].size()){
                        ans[row][col++] = 0;
                    }
                }else{
                    if(ans[i][j]==0)continue;
                    ans[i][j] = matrix[i][j];
                }
            }
        }
        matrix = ans;
    }
};