class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>temp ;
        temp = grid ;
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        while(k--){
            for(int i=0 ; i<=m ; i++){
                for(int j=0 ; j<=n ; j++){
                    if(j==n && i==m){
                        temp[0][0] = grid[i][j];
                    }else if(j==n){
                        temp[i+1][0] = grid[i][j];
                    }else {
                        temp[i][j+1] = grid[i][j];
                    }
                }
            }
            grid = temp ;
        }
        return grid;
    }
};