class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            sum += nums[i] % 2 == 0 ? nums[i] : 0;
        }
        
        for(auto query : queries) {
            if(nums[query[1]] % 2 == 0) {
                sum -= nums[query[1]];
            }
            
            nums[query[1]] += query[0];
            
            if(nums[query[1]] % 2 == 0) {
                sum += nums[query[1]];
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};