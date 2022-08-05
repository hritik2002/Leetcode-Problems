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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        
        if(n == 0)return NULL;
        if(n == 1)return new TreeNode(postorder[n - 1]);
        
        int root_val = postorder[n - 1];
        int count = 0, root_index = 0;
        
        for(int i = 0; i < n; i++){
            if(root_val == inorder[i]){
                root_index = i;
                break;
            }
        }
        
        vector<int> inRight, inLeft, postRight, postLeft;
        
        for(int i = 0; i < root_index; i++){
            inLeft.push_back(inorder[i]);
        }
        for(int i = root_index + 1; i < n; i++){
            inRight.push_back(inorder[i]);
            count++;
        }
        for(int i = n - 1 - count; i < n - 1; i++){
            postRight.push_back(postorder[i]);
        }
        for(int i = 0; i <  n - count - 1; i++){
            postLeft.push_back(postorder[i]);
        }
        
        TreeNode* root = new TreeNode(root_val);
        root->left = buildTree(inLeft, postLeft);
        root->right = buildTree(inRight, postRight);
        
        return root;
        
    }
};