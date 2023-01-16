class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nI) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        if(n == 0) {
            ans.push_back(nI);
            
            return ans;
        }
        int x = nI[0], y = nI[1];
        bool flag = true;
        
        for(int i = 0; i < n; ) {
            int a = intervals[i][0], b = intervals[i][1];
            int ansX = a, ansY = b;
            
            if(min(b, y) >= max(a, x))
                while(i < n && min(b, y) >= max(a, x)) {
                    ansX = min({ansX, x, a});
                    ansY = max({ansY, y, b});
                    flag = false;

                    i++;
                    if(i >= n) break;
                    a = intervals[i][0];
                    b = intervals[i][1];
                }
            else i++;
            
            ans.push_back({ansX, ansY});
        }
        
        if(flag) {
            ans.push_back(nI);
            sort(ans.begin(), ans.end());
        }
        
        return ans;
    }
};