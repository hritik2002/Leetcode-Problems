class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>mp;
        int count = 0 , ans = 0;
        
        for(auto num : nums){
            mp[num] = true ;
        }
        for(auto num : nums){
            count  = 0 ;
            
            if(!mp[num-1]){     // if the number is starting element of the sequence
                int currNum = num ;
                
                while(mp[currNum++])count++;
                
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};