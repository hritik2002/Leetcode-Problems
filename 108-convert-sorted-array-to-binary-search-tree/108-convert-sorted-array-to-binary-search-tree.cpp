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
    
    TreeNode* buildBST(vector<int> nums, int startIndex, int endIndex) {
        if(startIndex > endIndex) {
            return NULL;
        }
        
        int rootIndex = startIndex + (endIndex - startIndex + 1) / 2;
        TreeNode *root = new TreeNode(nums[rootIndex]);
        
        root->left = buildBST(nums, startIndex, rootIndex - 1);
        root->right = buildBST(nums, rootIndex + 1, endIndex);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int startIndex = 0, endIndex = nums.size() - 1;
        
        TreeNode* root = buildBST(nums, startIndex, endIndex);
        
        return root;
    }
};