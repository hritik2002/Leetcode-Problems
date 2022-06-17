class Solution {
public:
    set<vector<int>>st;
    void subsetHelper(vector<vector<int>>&result,vector<int>&subset,vector<int>nums,int index){
            // if(st.count(subset))return;Zzz
            st.insert(subset);
            result.push_back(subset);
        for(int i=index ; i<nums.size();i++){
            subset.push_back(nums[i]);
            subsetHelper(result,subset,nums,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>subset;
        int index = 0 ;
        subsetHelper(result,subset,nums,index);
        return result;
    }
};