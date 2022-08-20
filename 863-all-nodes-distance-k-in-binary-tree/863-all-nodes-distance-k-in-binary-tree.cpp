/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> res;
    set<TreeNode*> st;
    // 1) Find the target node
    // 2) Search for nodes at distance k
    
    void findTarget(TreeNode* root, TreeNode* target, int k, vector<TreeNode*> parentNodes) {
        if(root == NULL) {
            return;
        }
        if(root == target) {
            if(k == 0) {
                res.push_back(root->val);
                
                return;
            }
            st.insert(root);
            
            nodesAtKDistance(root->left, k - 1);
            nodesAtKDistance(root->right, k - 1);
            
            int n = parentNodes.size();
            
            for(int i = n - 1; i >= 0; i--) {
                nodesAtKDistance(parentNodes[i], k - n + i);
                st.insert(parentNodes[i]);
            }
            
            return;
        }
        
        parentNodes.push_back(root);
        
        findTarget(root->left, target, k, parentNodes);
        findTarget(root->right, target, k, parentNodes);
        
        return;
    }
    
    void nodesAtKDistance(TreeNode* root, int k) {
        if(root == NULL || k < 0 || st.count(root)) {
            return;
        }
        if(k == 0) {
            res.push_back(root->val);
            
            return;
        }
        
        nodesAtKDistance(root->left, k - 1);
        nodesAtKDistance(root->right, k - 1);
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findTarget(root, target, k, {});
        
        return res;
    }
};