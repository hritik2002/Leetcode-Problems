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
    int getMinMoves(TreeNode *root, int &minMoves) {
        if(root == NULL) {
            return 0;
        }
        
        int left = getMinMoves(root->left, minMoves);
        int right = getMinMoves(root->right, minMoves);
        
        minMoves += abs(left) + abs(right);
        
        return left + right + root->val - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        int minMoves = 0;
        
        getMinMoves(root, minMoves);
        
        return minMoves;
    }
};