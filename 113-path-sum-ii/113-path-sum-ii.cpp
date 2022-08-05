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
    void getPath(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> path) {
        if(root == NULL) {        
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            target -= root->val;
            path.push_back(root->val);
            
            if(target == 0) {
                ans.push_back(path);
            }
            
            return;
        }
        
        path.push_back(root->val);
        getPath(root->left, target - root->val, ans, path);
        getPath(root->right, target - root->val, ans, path);
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        getPath(root, targetSum, ans, path);
        
        return ans;
    }
};