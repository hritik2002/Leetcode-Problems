class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                int k = j + 1, l = n - 1;
                int a = nums[i], b = nums[j];
                
                while(k < l) {
                    long long sum = (long long)a + (long long)b + (long long)nums[k] + (long long)nums[l];
                    
                    if(sum == target && !st.count({a, b, nums[k], nums[l]})) {
                        ans.push_back({a, b, nums[k], nums[l]});
                        st.insert({a, b, nums[k], nums[l]});
                        k++;
                        l--;
                    }else if(sum < target) {
                        k++;
                    }else {
                        l--;
                    }
                }
            }
        }
        
        return ans;
    }
};