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
    void dfs(TreeNode* root, vector<int> &arr) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            arr.push_back(root->val);
            
            return;
        }
        
        dfs(root->left, arr);
        dfs(root->right, arr);
        
        return;
    } 
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafsOfTree1, leafsOfTree2;
        
        dfs(root1, leafsOfTree1);
        dfs(root2, leafsOfTree2);
        
        if(leafsOfTree1.size() != leafsOfTree2.size()) {
            return false;
        }
        
        int n = leafsOfTree1.size();
        
        for(int i = 0; i < n; i++) {
            if(leafsOfTree1[i] != leafsOfTree2[i]) {
                return false;
            }
        }
        
        return true;
    }
};