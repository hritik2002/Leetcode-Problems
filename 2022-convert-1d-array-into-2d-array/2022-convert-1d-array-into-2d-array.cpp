class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>arr;
        if(m*n!=original.size())return arr;
        for(int i=0;i<original.size();i++){
            ans[i/n][i%n] = original[i];
        }
        return ans;
    }
};