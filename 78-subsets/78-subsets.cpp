class Solution {
public:
    void getSubsets(vector<int> &nums, vector<int> &arr, vector<vector<int>> &res, int index, int size) {
        if(index >= size) {
            res.push_back(arr);
            
            return;
        }
        
        getSubsets(nums, arr, res, index + 1, size);
        arr.push_back(nums[index]);
        getSubsets(nums, arr, res, index + 1, size);
        arr.pop_back();
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        int size = nums.size();
        
        getSubsets(nums, arr, res, 0, size);
        
        return res;
    }
};