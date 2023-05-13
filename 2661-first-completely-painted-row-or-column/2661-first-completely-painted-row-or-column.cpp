class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        map<int, pair<int, int>> mp;
        vector<int> row(mat.size() + 1, 0), col(mat[0].size() + 1, 0);
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        
        for(int i = 0; i < n; i++) {
            pair<int, int> ind = mp[arr[i]];
            col[ind.second]++;
            row[ind.first]++;
            if(col[ind.second] == mat.size()) return i;
            if(row[ind.first] == mat[0].size()) return i;
        }
        
        return -1;
    }
};