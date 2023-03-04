class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 0;
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            vector<int> tmp;
            for(int j = i; j < n; j++) {
                if(nums[j] % p == 0) {
                    cnt++;
                }
                tmp.push_back(nums[j]);
                if(cnt > k) {
                    break;
                }
                st.insert(tmp);
            }
        }
        
        return st.size();
    }
};