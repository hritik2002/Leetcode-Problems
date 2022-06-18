class Solution {
public:
   
    void helper(vector<int>nums,vector<vector<int>>&res,vector<int>sub,int ind){
            res.push_back(sub);
         set<int>st;
        for(int i=ind;i<nums.size();i++){
            if(nums[i]==nums[ind] && i!=ind)continue;
            if(st.count(nums[i])){continue;}
            st.insert(nums[i]);
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