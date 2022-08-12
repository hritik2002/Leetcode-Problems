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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        stack<TreeNode*> nodeStack;
        
        TreeNode* curr = root;
        while(curr || nodeStack.size() > 0) {
            while(curr) {
                nodeStack.push(curr);
                curr = curr->left;
            }
            
            curr = nodeStack.top();
            nodeStack.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        
        return ans;
    }
};