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
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        
        int minDiff = INT_MAX;
        stack<TreeNode*> nodes;
        TreeNode* curr = root, *prev = NULL;
        
        while(curr || nodes.size()) {
            while(curr) {
                nodes.push(curr);
                curr = curr->left;
            }
            
            if(nodes.size()) {
                curr = nodes.top();
                nodes.pop();
            }
            
            if(curr) {
                if(prev != NULL) {
                    minDiff = min(minDiff, abs(prev->val - curr->val));
                }
                prev = curr;
                curr = curr->right;
            }
        }
        
        
        
        return minDiff;
    }
};