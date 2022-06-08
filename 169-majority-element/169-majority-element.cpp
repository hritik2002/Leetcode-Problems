class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>store;
        int count = 0 , ans = -1 ;
        for(int i=0 ; i<nums.size();i++){
            if(store[nums[i]]){
                store[nums[i]]++;
            }
            else {
                store[nums[i]] = 1 ;
            }
            if(store[nums[i]]>count){
                count = store[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
        
    }
};