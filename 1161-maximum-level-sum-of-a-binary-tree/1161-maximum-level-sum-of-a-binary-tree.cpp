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
    map<int, long long> mp;
    //dfs
    void dfs(TreeNode* root, int level) {
        if(root == NULL) {
            return;
        }
        
        dfs(root->left, level + 1);
        mp[level] += root->val;
        dfs(root->right, level + 1);
        
        return;
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        
        int maxVal = INT_MIN, level = 1;
        for(auto level_sum : mp) {
            if(level_sum.second > maxVal) {
                level = level_sum.first;
                maxVal = level_sum.second;
            }
        }
        
        return level;
    }
};