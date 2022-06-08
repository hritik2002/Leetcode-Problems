class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        map<int,int>store;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(store[nums[i]]){
                store[nums[i]]++;
            }else{
                store[nums[i]] = 1 ;
            }
            if(store[nums[i]]>n/3){
                ans.push_back(nums[i]);
                store[nums[i]] = INT_MIN ;
            }
        }
        return ans;
    }
};