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
    void dfs(TreeNode* root , map<int , int> &storeSum,int& sum){
        if(root==NULL)return;
        dfs(root->right,storeSum,sum);
        sum += root->val ;
        storeSum[root->val] = sum ;
        dfs(root->left,storeSum,sum);
    }
    void dfs2(TreeNode* root , map<int,int>&storeSum){
        if(root==NULL)return ;
        root->val = storeSum[root->val];
        dfs2(root->left,storeSum);
        dfs2(root->right,storeSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        map<int , int > storeSum ;
        int sum = 0 ;
        dfs(root,storeSum,sum);
        dfs2(root,storeSum);
        return root;
    }
};