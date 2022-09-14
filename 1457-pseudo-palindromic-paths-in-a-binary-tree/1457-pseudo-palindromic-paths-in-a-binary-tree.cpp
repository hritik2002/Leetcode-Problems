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
    int count = 0;
    
    void findPseudoPalindromicPaths(TreeNode* root, map<int, int> &visitedNodes) {
        if(root == NULL) {
            return;
        }
        
        visitedNodes[root->val]++;
        
        if(root->left == NULL && root->right == NULL) {
            
            int oddNumberOfNodes = 0;
            for(auto node : visitedNodes) {
                if(node.second % 2 == 1) {
                    oddNumberOfNodes++;
                }
            }
            
            if(oddNumberOfNodes <= 1) {
                count++;
            }
            
        }
        
        
        findPseudoPalindromicPaths(root->left, visitedNodes);
        findPseudoPalindromicPaths(root->right, visitedNodes);
        
        visitedNodes[root->val]--;
        
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> visitedNodes;
        findPseudoPalindromicPaths(root, visitedNodes);
        
        return count;
    }
};