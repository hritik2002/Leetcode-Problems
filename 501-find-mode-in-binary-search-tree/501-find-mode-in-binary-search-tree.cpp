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
    map<int, int> hm;
    int maxCount = 0;
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        hm[root->val]++;
        maxCount = max(maxCount, hm[root->val]);
        
        dfs(root->left);
        dfs(root->right);
        
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        
        dfs(root);
        
        for(auto node_count : hm) {
            if(node_count.second == maxCount) {
                ans.push_back(node_count.first);
            }
        }
        
        return ans;
    }
};