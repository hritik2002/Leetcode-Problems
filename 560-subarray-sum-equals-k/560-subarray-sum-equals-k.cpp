class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int sum=0,ans=0;
        
        mp[sum] = 1;
        
        for(auto num:nums){
            sum += num;
            int find = sum - k;
            
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            
            mp[sum]++;
        }
        
        return ans;
    }
};