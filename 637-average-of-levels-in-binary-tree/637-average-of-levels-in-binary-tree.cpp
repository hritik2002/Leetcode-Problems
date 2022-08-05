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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        long long int sum = 0, count = 0;
        
        while(nodeQueue.size() > 0) {
            TreeNode* front = nodeQueue.front();
            nodeQueue.pop();
            
            if(front == NULL) {
                res.push_back(double((double)sum / count));
                count = 0, sum = 0;
                
                if(nodeQueue.size() > 0) {
                    nodeQueue.push(NULL);
                }
                
            }else{
                sum += front->val;
                count++;
                if(front->left) {
                    nodeQueue.push(front->left);   
                }
                if(front->right){
                    nodeQueue.push(front->right);
                }
            }
        }
        
        return res;
    }
};