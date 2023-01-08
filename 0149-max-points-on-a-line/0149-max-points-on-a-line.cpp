class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        
        for(int i = 0; i < n; i++) {
            map<string, int> mp;
            int dup = 1;
            
            for(int j = i + 1; j < n; j++) {
                int dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
                
                if(dx == 0 && dy == 0) {
                    dup++;
                }else {
                    int gcd = __gcd(dx, dy);
                    string key = to_string(dx / gcd) + "_" + to_string(dy / gcd);
                    mp[key]++;
                }
            }
            
            ans = max(ans, dup);
            for(auto m : mp) {
                ans = max(ans, m.second + dup);
            }
        }
        
        return ans;
    }
};