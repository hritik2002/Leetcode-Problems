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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        int max_node = INT_MIN;

        while(que.size() > 0){
            TreeNode* front = que.front();
            que.pop();
            if(front == NULL){
                ans.push_back(max_node);
                max_node = INT_MIN;
                
                if(que.size() > 0){
                    que.push(NULL);
                }
                
            }else{
                max_node = max(max_node, front->val);
                
                if(front->left){
                    que.push(front->left);
                }
                
                if(front->right){
                    que.push(front->right);
                }
            }
            
        }
        
        return ans;
    }
};