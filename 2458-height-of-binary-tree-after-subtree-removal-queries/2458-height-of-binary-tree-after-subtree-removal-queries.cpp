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
    int d1[100002], d2[100002], depth[100002], level[100002];
    int traverse(TreeNode* root, int l) {
        if(root == NULL) {
            return 0;
        }
        level[root->val] = l;
        depth[root->val] = 1 + max(traverse(root->left, l + 1), traverse(root->right, l + 1));
        
        if(d1[l] < depth[root->val]) {
            d2[l] = d1[l];
            d1[l] = depth[root->val];
        }else if(d2[l] < depth[root->val]) {
            d2[l] = depth[root->val];
        }
        
        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        traverse(root, 0);
        
        for(auto q : queries) {
            int l = level[q];
            ans.push_back(l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1);
        }
        
        return ans;
    }
};