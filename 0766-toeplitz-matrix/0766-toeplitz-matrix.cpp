class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int prev = matrix[0][0], n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i != 0 && j != 0) {
                    continue;
                }
                int x = i, y = j;
                prev = matrix[i][j];
                while(x < n && y < m) {
                    if(matrix[x][y] != prev) return false;
                    x++;
                    y++;
                }
            }
        }
        
        
        return true;
    }
};