class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        map<int, int> mp;
        set<int> st;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        for(auto x : mp) {
            if(st.count(x.second)) {
                return false;   
            }
            
            st.insert(x.second);
        }
        
        return true;
    }
};