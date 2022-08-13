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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        
        stack<TreeNode*> treeNode1, treeNode2;
        TreeNode* node1 = root1, *node2 = root2;
        
        while(node1 || node2 || treeNode1.size() || treeNode2.size()) {
            while(node1) {
                treeNode1.push(node1);
                node1 = node1->left;
            }
            while(node2) {
                treeNode2.push(node2);
                node2 = node2->left;
            }
            
            if(treeNode1.size()) {
                node1 = treeNode1.top();
            }
            if(treeNode2.size()) {
                node2 = treeNode2.top();
            }
            
            if(node1 && node2) {
                if(node1->val <= node2->val) {
                    treeNode1.pop();
                    ans.push_back(node1->val);
                    node1 = node1->right;
                    node2 = NULL;
                }else {
                    treeNode2.pop();
                    ans.push_back(node2->val);
                    node2 = node2->right;
                    node1 = NULL;
                }
            }else {
                if(node1) {
                    treeNode1.pop();
                    ans.push_back(node1->val);
                    node1 = node1->right;
                }else {
                    treeNode2.pop();
                    ans.push_back(node2->val);
                    node2 = node2->right;
                }
            }      
            
        }
        
        return ans;
    }
};