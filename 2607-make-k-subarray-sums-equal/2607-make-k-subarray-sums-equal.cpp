class Solution {
public:
    long long makeSubKSumEqual(vector<int>& nums, int k) {
        long long ans = 0;
        int n = size(nums);
        vector<int> vis(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                vector<int> val;
                int tmp = i;
                
                while(vis[tmp] == 0) {
                    val.push_back(nums[tmp]);
                    vis[tmp] = 1;
                    tmp = (tmp + k) % n;
                }
                
                sort(val.begin(), val.end());
                int size = val.size();
                
                int med = val[size / 2];
                if(size % 2 == 0) {
                    med = (val[size / 2] + val[(size) / 2 - 1]) / 2;
                }
                
                for(auto n : val) {
                    ans += abs(n - med);
                }
            }
        }
        
        return ans;
    }
};