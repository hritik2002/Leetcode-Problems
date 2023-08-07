class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        
        while(j >= 0 && i < n) {
            if(matrix[i][j] == target) {
                return true;
            }else if(matrix[i][j] < target) {
                i++;
            }else {
                j--;
            }
        }
        
        return false;
    }
};