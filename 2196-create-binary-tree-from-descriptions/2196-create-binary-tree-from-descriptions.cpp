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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> parent, valueToAddr;
        
        for(auto desc : descriptions) {
            int node = desc[0], child = desc[1], left = desc[2];
            TreeNode* currNode;
            TreeNode* childNode;
            
            if(!valueToAddr[node]) {
                currNode = new TreeNode(node);
                valueToAddr[node] = currNode;
            }else currNode = valueToAddr[node];
            
            if(!valueToAddr[child]) {
                childNode = new TreeNode(child);
                valueToAddr[child] = childNode;
            }else childNode = valueToAddr[child];
            if(left) {
                currNode->left = childNode;
            }else {
                currNode->right = childNode;
            }
            
            parent[child] = currNode;
        }
        
        for(auto node : valueToAddr) {
            if(!parent[node.first]) {
                return node.second;
            }
        }
        
        return NULL;
    }
};