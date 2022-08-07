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
    map<int, int> mp;
    
    void dfs(TreeNode* root, int level) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            mp[level] += root->val;
            
            return;
        }
        
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
        
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        int maxVal = 0;
        
        for(auto x : mp) {
            cout<<x.first<<" "<<x.second<<endl;
            
            maxVal = x.second;
        }
        
        return maxVal;
    }
};