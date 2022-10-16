class Solution {
public:
    bool check(vector<int> &nums, long long val) {
        long long cnt = 0;
        
        for(auto n : nums) {
            cnt += (n - val);
            
            if(cnt > 0) {
                return false;
            }
        }
        
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        auto temp = nums;
        sort(temp.begin(), temp.end());
        long long start = temp[0], end = temp[n - 1];
        long long ans = 0;
        
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            
            if(check(nums, mid)) {
                end = mid - 1;
                ans = mid;
            }else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};