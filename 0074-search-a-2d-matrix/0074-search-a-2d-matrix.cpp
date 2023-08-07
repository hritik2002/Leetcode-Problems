class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        vector<int> arr;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr.push_back(matrix[i][j]);
            }
        }
        
        int l = 0, h = m * n - 1;
        
        while(l <= h) {
            int mid = h - (h - l) / 2;
            
            if(arr[mid] == target) {
                return true;
            }else if(arr[mid] < target) {
                l = mid + 1;
            }else h = mid - 1;
        }
        
        return false;
    }
};