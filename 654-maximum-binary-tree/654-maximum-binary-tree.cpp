/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getMaxBinaryTree(int start, int end, vector<int> &nums) {
        if(start > end) {
            return NULL;
        }
        
        int maxVal = INT_MIN, index = 0;
        for(int i = start; i <= end; i++) {
            if(maxVal < nums[i]) {
                maxVal = nums[i];
                index = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[index]);
        root->left = getMaxBinaryTree(start, index - 1, nums);
        root->right = getMaxBinaryTree(index + 1, end, nums);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        
        return getMaxBinaryTree(0, n - 1, nums);
    }
};