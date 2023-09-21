class Solution {
public:
    static bool endSort(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), endSort);
             
        int prevEnd = points[0][1];
        int ans = 1;
        int size = points.size();
        
        for(int i = 1; i < size; i++) {
            int currentStart = points[i][0];
            
            if(currentStart > prevEnd) {
                prevEnd = points[i][1];
                ans++;
            }
        }
        
        return ans;
    }
};