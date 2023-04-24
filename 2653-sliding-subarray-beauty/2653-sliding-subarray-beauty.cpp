class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int, int> mp;
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            
            if(i - k + 1 >= 0) {
                if(i - k >= 0) {
                    mp[nums[i - k]]--;
                }
                
                int tmp = x;
                for(auto m : mp) {
                    tmp -= m.second;
                    
                    if(tmp <= 0) {
                        ans.push_back(m.first < 0 ? m.first : 0);
                        break;
                    }
                }
            }
            
        }
        
        return ans;
    }
};