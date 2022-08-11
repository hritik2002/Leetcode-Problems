class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0, n = nums.size();
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        for(auto num : nums) {
            if(mp[num + diff]) {
                if(mp[num + 2*diff]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};