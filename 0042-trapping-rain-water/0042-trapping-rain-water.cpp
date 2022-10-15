class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightArr(n, 0);
        
        if(n == 0) {
            return 0;
        }
        
        rightArr[n - 1] = height[n - 1];
        
        // right to left storing max height
        for(int i = n - 2; i >= 0; i--) {
            rightArr[i] = max(rightArr[i + 1], height[i]);
        }
        
        int trappedWater = 0;
        int leftMax = 0;
        
        for(int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            trappedWater += min(leftMax, rightArr[i]) - height[i];
        }
        
        
        
        return trappedWater;
    }
};