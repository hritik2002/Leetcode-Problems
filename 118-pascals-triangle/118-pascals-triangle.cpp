class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int currentRow = 0;
        
        while(numRows--){
            int i = 0, n = ans.size() - 1;
            vector<int> child;
            
            child.push_back(1);
            
            while(i < currentRow - 1){
                child.push_back(ans[n][i] + ans[n][i + 1]);
                i++;
            }
            
            if(currentRow == 0){
                ans.push_back(child);
                currentRow++;
                
                continue;
            }
            
            child.push_back(1);
            ans.push_back(child);
            currentRow++;
        }
        
        return ans;
    }
};