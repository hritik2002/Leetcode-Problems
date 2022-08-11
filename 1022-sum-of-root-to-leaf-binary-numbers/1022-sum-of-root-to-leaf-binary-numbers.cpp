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
    int ans = 0;
    int sumRootToLeaf(TreeNode* root, int sum = 0) {
        if(root == NULL) {
            return 0;
        }
        sum = sum*2 + root->val;
        
        if(root->left == NULL && root->right == NULL) {
            ans += sum;
            return ans;
        }
        
        int left = sumRootToLeaf(root->left, sum);
        int right = sumRootToLeaf(root->right, sum);
        
        return ans;
    }
};