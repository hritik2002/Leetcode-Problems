class Solution {
public:
    vector<int> getRecoveredArray(vector<int>& nums, unordered_map<int, int>& map, int diff) {
        auto mp = map;
        int k = diff / 2, size = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < size; i++) {
            if(mp[nums[i]] && mp[nums[i] + diff]) {
                ans.push_back(nums[i] + k);
                mp[nums[i]]--;
                mp[nums[i] + diff]--;
            }else if(mp[nums[i]] && !mp[nums[i] + diff]) return {};
        }
        
        return ans;
    }
    vector<int> recoverArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int size = nums.size();
        
        for(auto num : nums) {
            mp[num]++;
        }
        sort(begin(nums), end(nums));
        
        for(int i = 1; i < size; i++) {
            int diff = nums[i] - nums[0];
            if(diff <= 0 || diff % 2 != 0) {
                continue;
            }
            auto ans = getRecoveredArray(nums, mp, diff);
            if(ans.size() == size / 2) {
                return ans;
            }
        }
        
        return {};
    }
};