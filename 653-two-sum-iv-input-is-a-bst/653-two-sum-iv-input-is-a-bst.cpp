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
    map<int, int> presentNodes;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        
        bool left = findTarget(root->left, k);
        bool right = findTarget(root->right, k);
        
        if(left == true || right == true) {
            return true;
        }
        
        if(presentNodes[k - root->val]) {
            return true;
        }else {
            presentNodes[root->val]++;
        }
        
        return left || right;
    }
};