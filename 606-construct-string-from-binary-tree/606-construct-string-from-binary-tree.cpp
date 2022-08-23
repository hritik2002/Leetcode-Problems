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
    int cnt = 0;
    string tree2str(TreeNode* root) {
        if(root == NULL) {
            cnt = 1;
            return "";
        }
        if(root->left == NULL && root->right == NULL) {
            return to_string(root->val);
        }
        
        string ans = to_string(root->val);
        
        string left = tree2str(root->left);
        
        if(left.length()) {
            ans += "(" + left + ")";
        }else if(cnt == 1) {
            ans += "()";
            cnt++;
        }
        string right = tree2str(root->right);
        
        if(right.length()) {
            ans += "(" + right + ")";
        }
        
        return ans;
        
    }
};