class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        double mini = INT_MAX, index = -1;
        int n = points.size();
        
        for(int i = 0; i < n; i++) {
            if(x == points[i][0] || y == points[i][1]) {
                int x_dist = abs(x - points[i][0]);
                int y_dist = abs(y - points[i][1]);
                double dist = sqrt(x_dist + y_dist);
                
                if(dist < mini) {
                    mini = dist;
                    index = i;
                }
            }
        }
        
        return index;
    }
};