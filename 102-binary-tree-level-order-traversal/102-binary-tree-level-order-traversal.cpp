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
    void levelOrder(TreeNode* root, vector<vector<int>>&res){
        if(!root)return;
        
        queue<TreeNode* >q;
        vector<int>temp;
        q.push(root);
        q.push(NULL);
        
        while(q.size()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front)
                temp.push_back(front->val);
            if(front == NULL){
                q.push(NULL);
                res.push_back(temp);
                vector<int>t;
                temp = t;
                if(q.size() == 1)return;
                
                continue;
            }
            
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        levelOrder(root,res);
        return res;
    }
};