class Solution {
public:
   
    vector<int> searchRange(vector<int>& nums, int target) {
        int min_index = INT_MAX, max_index = INT_MIN,
            low = 0, high = nums.size() - 1;
        
        findIndex(nums, target, min_index, max_index, low, high);
        
        vector<int>ans ;
        
        if(min_index == INT_MAX){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(min_index);
        ans.push_back(max_index);
        
        return ans;
    }
    
    void findIndex(vector<int>& nums, int target, int &min_index, int &max_index, int low, int high){
        if(low>high){
            return ;
        }
        int mid = low + (high - low)/2 ;
        if(nums[mid] == target){
            min_index = min(min_index, mid);
            max_index = max(max_index, mid);
            findIndex(nums, target, min_index, max_index, low, mid - 1);
            findIndex(nums, target, min_index, max_index, mid + 1, high);
        }else if(nums[mid] < target){
            findIndex(nums, target, min_index, max_index, mid + 1, high);
        }else{
            findIndex(nums, target, min_index, max_index, low, mid - 1);
        }
        
    }
};
