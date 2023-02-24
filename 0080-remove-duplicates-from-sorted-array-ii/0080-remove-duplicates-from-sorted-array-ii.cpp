class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, n = nums.size(), j = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] < 2) {
                k++;
                nums[j] = nums[i];
                j++;
            }
            
            mp[nums[i]]++;
            
        }
        
        return k;
    }
};