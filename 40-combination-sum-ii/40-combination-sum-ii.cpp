class Solution {
public:
    set<vector<int>>st;
    void helper(vector<int>& nums,vector<vector<int>>&res,vector<int>subset,int sum,int target,int index){
        if(sum>target)return;
        else if(sum==target){
            if(st.count(subset))return;
            st.insert(subset);
            res.push_back(subset);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[index])continue;
            sum += nums[i];
            subset.push_back(nums[i]);
            helper(nums,res,subset,sum,target,i+1);
            sum -= nums[i];
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>subset;
        int sum = 0, index = 0;
        sort(candidates.begin(),candidates.end());
        helper(candidates,res,subset,sum,target,index);
        return res;
    }
};