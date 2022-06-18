class Solution {
public:
    set<vector<int>>st;
    void helper(vector<int>nums,vector<vector<int>>&res,vector<int>sub,int ind){
        if(!st.count(sub)){
            st.insert(sub);
            res.push_back(sub);
            // reverse(sub.begin(),sub.end());
            // st.insert(sub);
            // reverse(sub.begin(),sub.end());
        }
        for(int i=ind;i<nums.size();i++){
            if(nums[i]==nums[ind] && i!=ind)continue;
            helper(nums,res,sub,i+1);
            sub.push_back(nums[i]);
            helper(nums,res,sub,i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        int index = 0 ;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        helper(nums,res,subset,index);
        return res;
    }
};