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
    void dfs(TreeNode* root, string parentDirection, int score) {
        if (root == NULL) {
            return;
        }
        
        ans = max(ans, score);
        
        if (parentDirection == "R") {
            dfs(root->left, "L", score + 1);        // go left with score + 1
            dfs(root->left, "R", 1);               // go right with score = 1
        }else {
            dfs(root->right, "R", score + 1);       // go right with score + 1
            dfs(root->right, "L", 1);                // go left with score = 1
        }
        
        return;
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        dfs(root, "R", 1);
        dfs(root, "L", 1);
        
        return ans - 1;
    }
};