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
    int findMinNode(TreeNode* root) {
        if(root->left == NULL) {
            return root->val;
        }
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
        
        int left = findMinNode(root->left);
        
        return left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // search
        // delete
        
        if(root == NULL) {
            return root;
        } 
        if(root->val == key) {
            // found the key
            if(root->left == NULL && root->right == NULL) {
                return NULL;
            }
            
            if(root->left == NULL) {
                return root->right;
            }else if(root->right == NULL) {
                return root->left;
            }else {
                root->val = findMinNode(root->right);
                cout<<root->val<<endl;
                root->right = deleteNode(root->right, root->val);
            }
        }else {
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
        }
        
        
        
        return root;
    }
};