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
    int findTilt(TreeNode* root, int &ans) {
        if(root == NULL) {
            return 0;
        }
        
        int left = findTilt(root->left, ans);
        int right = findTilt(root->right, ans);
        
        int sum = left + right + root->val;
        root->val = abs(left - right);
        ans += root->val;
        
        return sum;
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        
        findTilt(root, ans);
        
        return ans;
    }
};