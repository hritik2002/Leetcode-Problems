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
    void helper(TreeNode* root , vector<int>&arr){
        if(!root)return;
        helper(root->left,arr);
        arr.push_back(root->val);
        helper(root->right,arr);
    }
    void helper2(TreeNode* root , int &ans,int &k){
        if(!root)return;
        helper2(root->left,ans,k);
        k--;
        if(k==0){
            ans = root->val ;
        }
        helper2(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr ;
        int ans = 0 ;
        // helper(root,arr);
        helper2(root,ans,k);
        return ans;
        // sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};
