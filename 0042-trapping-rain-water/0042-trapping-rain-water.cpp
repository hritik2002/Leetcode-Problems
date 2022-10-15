class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftArr(n, 0), rightArr(n, 0);
        
        if(n == 0) {
            return 0;
        }
        
        leftArr[0] = height[0];
        rightArr[n - 1] = height[n - 1];
        
        // right to left storing max height
        for(int i = n - 2; i >= 0; i--) {
            rightArr[i] = max(rightArr[i + 1], height[i]);
        }
        
        int trappedWater = 0;
        
        trappedWater += min(leftArr[0], rightArr[0]) - height[0];
        for(int i = 1; i < n; i++) {
            leftArr[i] = max(leftArr[i - 1], height[i]);
            trappedWater += min(leftArr[i], rightArr[i]) - height[i];
        }
        
        
        
        return trappedWater;
    }
};