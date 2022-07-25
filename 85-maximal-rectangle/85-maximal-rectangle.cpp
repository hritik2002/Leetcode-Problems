class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            Find first smallest element from left and right
            calculate area between left and right and store the max.
        */
        int n = heights.size();
        stack<int> stck, stck1;
        vector<int> smallerLeft(n, 0);
        vector<int> smallerRight(n, 0);
        
        for(int i = 0; i < n; i++){
            while(stck.size() > 0 && heights[stck.top()] >= heights[i]){
                stck.pop();
            }
            if(stck.size() > 0){
                smallerLeft[i] = stck.top() + 1;
            }else{
                smallerLeft[i] = 0;
            }
            
            stck.push(i);
        }
        
        // while(stck.size() > 0)stck.pop();
        
        for(int i = n - 1; i >= 0; i--){
            while(stck1.size() > 0 && heights[stck1.top()] >= heights[i]){
                stck1.pop();
            }
            if(stck1.size() > 0){
                smallerRight[i] = stck1.top() - 1;
            }else{
                smallerRight[i] = n - 1;
            }
            
            stck1.push(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int area = (smallerRight[i] - smallerLeft[i] + 1)*heights[i];
            ans = max(ans, area);
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> newMatrix(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1' && i > 0){
                    newMatrix[i][j] = newMatrix[i-1][j] + 1;
                }else{
                    newMatrix[i][j] = matrix[i][j] - 48;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
                ans = max(ans, largestRectangleArea(newMatrix[i]));
        }
        
        return ans;
        
    }
};