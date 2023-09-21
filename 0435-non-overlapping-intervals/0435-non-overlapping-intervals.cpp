bool customSort(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customSort);
        
        int size = intervals.size();
        int count = 0;
        
        int prevEnd = intervals[0][1];
        
        for(int i = 1; i < size; i++) {
            int currentStart = intervals[i][0];
            
            if(currentStart >= prevEnd) {
                prevEnd = intervals[i][1];
            }else {
                count++;
            }
        }
        
        return count;
    }
};