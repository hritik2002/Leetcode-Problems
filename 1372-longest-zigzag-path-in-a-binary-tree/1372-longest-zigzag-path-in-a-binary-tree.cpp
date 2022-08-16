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
    void solve(TreeNode* root , int score, int dir){
        if(root == NULL) return ;
        
        ans = max(ans, score);
        
        if(dir == 0) {
            solve(root->right, score + 1, 1);
            solve(root->left, 1, 0);
        }
        else {
            solve(root->left, score + 1, 0);
            solve(root->right, 1, 1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        
           solve(root->left, 1, 0);
           solve(root->right, 1, 1);
        
           return ans;
    }
};