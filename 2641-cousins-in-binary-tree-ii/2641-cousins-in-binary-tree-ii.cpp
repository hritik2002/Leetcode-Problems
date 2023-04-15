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
    unordered_map<int, vector<pair<TreeNode*, int>>> mp;
    void dfs(TreeNode* root, TreeNode* parent, int depth) {
        if(!root) {
            return;
        }
        mp[depth].push_back({parent, root->val});
        dfs(root->left, root, depth + 1);
        dfs(root->right, root, depth + 1);
        
        return;
    }
    void changeValue(TreeNode* root, TreeNode* parent, int depth) {
        if(!root) {
            return;
        }
        
        
        changeValue(root->left, root, depth + 1);
        changeValue(root->right, root, depth + 1);
        
        root->val = 0;
        long long sum = 0;
        for(auto val : mp[depth]) {
            if(val.first != parent) {
                sum += val.second;
            }
        }
        root->val = sum;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root, NULL, 1);
        changeValue(root, NULL, 1);
        
        return root;
    }
};