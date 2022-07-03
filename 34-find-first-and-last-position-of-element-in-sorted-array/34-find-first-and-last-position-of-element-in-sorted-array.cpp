class Solution {
public:
   
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans ;
        int first = INT_MAX , second = INT_MIN ;
        ans.push_back(-1);
        ans.push_back(-1);
        
        helper(nums,0,nums.size()-1,target,first,second);
        
        if(first!=INT_MAX){
            ans[0] = first;
        }
        if(second!=INT_MIN){
            ans[1] = second;
        }
        
        return ans;
    }
     void helper(vector<int>&nums,int low , int high ,int target , int &first , int &second ){
        if(low <= high){
            int mid ;
            mid = low + (high-low)/2 ;
            if(nums[mid]==target){
                first = min(first , mid);
                second = max(second , mid );
            }
            
            helper(nums,low,mid-1,target,first,second);   // left
            helper(nums,mid+1,high,target,first,second);  // right
      
        }
   }
        
};