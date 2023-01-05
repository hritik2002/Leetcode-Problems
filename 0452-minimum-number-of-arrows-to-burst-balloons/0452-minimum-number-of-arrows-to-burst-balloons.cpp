class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int last = points[0][1];
        sort(points.begin(), points.end());
        int cnt = 1;
        
        for(auto point : points) {
            if(last < point[0]) {
                last = point[1];
                cnt++;
            }
            
            last = min(last, point[1]);
        }
        
        return cnt;
    }
};