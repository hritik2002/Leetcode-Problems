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
    TreeNode* getBST(vector<int>& preorder, int minValue, int maxValue, int& start, int end){
        if(start > end) {
            return NULL;
        }
        if(preorder[start] < minValue || preorder[start] > maxValue) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[start++]);
        TreeNode* left = getBST(preorder, minValue, root->val, start, end);
        TreeNode* right = getBST(preorder, root->val, maxValue, start, end);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int start = 0;
        
        return getBST(preorder, INT_MIN, INT_MAX, start, n - 1);
    }
};