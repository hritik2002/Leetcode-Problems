class Solution {
public:
    void helper(vector<int>nums,vector<vector<int>>&res,int sum,int target,int index,vector<int>subset){
        if(sum>target)return ;
        else if(sum==target){
            res.push_back(subset);
        }
        for(int i=index ; i<nums.size();i++){
            sum += nums[i];
            subset.push_back(nums[i]);
            helper(nums,res,sum,target,i,subset);
            subset.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        int sum = 0 , index = 0 ;
        vector<int>subset;
        helper(candidates,res,sum,target,index,subset);
        return res;
    }
};