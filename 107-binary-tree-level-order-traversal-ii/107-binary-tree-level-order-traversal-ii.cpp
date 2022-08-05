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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL){
            return res;
        }
        
        stack<TreeNode*> nodeStack;
        queue<TreeNode*> nodeQueue;
        
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        nodeStack.push(NULL);
        nodeStack.push(root);
        nodeStack.push(NULL);
        
        while(nodeQueue.size() > 0){
            TreeNode* frontNode = nodeQueue.front();
            nodeQueue.pop();
            
            if(frontNode == NULL){
                
                if(nodeQueue.size() > 0){
                    nodeQueue.push(NULL);
                    nodeStack.push(NULL);
                }
                
            }else{
                
                if(frontNode->right != NULL){
                    nodeQueue.push(frontNode->right);
                    nodeStack.push(frontNode->right);
                }
                if(frontNode->left != NULL){
                    nodeQueue.push(frontNode->left);
                    nodeStack.push(frontNode->left);
                }
                
            }
        }
        
        vector<int> rowNodes;
        nodeStack.pop();
        
        while(nodeStack.size() > 0){
            TreeNode* top = nodeStack.top();
            nodeStack.pop();
            
            if(top == NULL){
                res.push_back(rowNodes);
                vector<int> temp;
                rowNodes = temp;
            }else{
                rowNodes.push_back(top->val);
            }
        }
        
        return res;
    }
};