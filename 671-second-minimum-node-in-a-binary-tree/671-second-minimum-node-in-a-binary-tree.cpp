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
    
    map<int, int> hm;
    
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        hm[root->val]++;
        
        dfs(root->left);
        dfs(root->right);
        
        return;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        
        dfs(root);
        
        if(hm.size() == 1) {
            return -1;
        }
 
        int count = 0;
        
        for(auto __map: hm) {
            if(count == 1) {
                return __map.first;
            }
            
            count++;
        }
        return -1;
    }
};