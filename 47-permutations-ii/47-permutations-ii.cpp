class Solution {
public:
    set<vector<int>>st;
    void helper(vector<int>nums,vector<vector<int>>&ans,int index){
        if(index==nums.size()-1){
            if(st.count(nums))return ;
            st.insert(nums);
            ans.push_back(nums);
            return ;
        }
        for(int i=index ; i<nums.size(); i++){
            if(i!=index && nums[i]==nums[index]){
                continue;
            }
            swap(nums[i],nums[index]);
            helper(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(nums,ans,0);
        return ans;
    }
};