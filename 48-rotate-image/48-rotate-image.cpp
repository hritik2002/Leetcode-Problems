class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size() ;
        for(int i=0;i<m ;i++){
            for(int j=i;j<n ;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i] ;
                matrix[j][i] = temp ;
            }
        }
        for(int i=0;i<(n+1)/2;i++){
            for(int j=0;j<m;j++){
                int temp = matrix[j][i];
                matrix[j][i] = matrix[j][n-1-i] ;
                matrix[j][n-1-i] = temp ;
            }
        }
    }
};