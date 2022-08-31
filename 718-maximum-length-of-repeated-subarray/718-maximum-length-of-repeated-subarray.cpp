class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> arr(n + 1, vector<int> (m + 1, 0));
        int maxVal = 0;
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                }
                
                maxVal = max(maxVal, arr[i][j]);
            }
        }
        
        return maxVal;
    }
};