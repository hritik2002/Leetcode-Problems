class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0 ;
        int left = 0 , right = 0, max_sum=0 ;
        map<int,int>_map ;
        for(int i=0; i <nums.size();i++){
            
            
                while(_map[nums[right]]){
                    res -= nums[left];
                    _map[nums[left++]] = 0 ;
                };
                res = res + nums[right++];
                _map[nums[i]] = 1;
                
            max_sum = max(max_sum,res);
        }
        return max_sum;
    }
};