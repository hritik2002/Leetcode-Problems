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
    void getNodes(TreeNode* root, vector<int>& arr) {
        if(root == NULL) {
            return;
        }
        
        getNodes(root->left, arr);
        
        arr.push_back(root->val);
        
        getNodes(root->right, arr);
        
        return;
    }
    TreeNode* getBST(vector<int> &arr, int start, int end) {
        if(start > end) {
            return NULL;
        }
        
        int mid = start + (end - start) / 2;
        
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = getBST(arr, start, mid - 1);
        root->right = getBST(arr, mid + 1, end);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodesArr;
        
        getNodes(root, nodesArr);
        
        return getBST(nodesArr, 0, nodesArr.size() - 1);
    }
};