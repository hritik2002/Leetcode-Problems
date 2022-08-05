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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root == NULL)return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool flag = false;
        vector<int> temp;
        
        while(q.size() > 0){
            TreeNode* front = q.front();
            q.pop();
            
            if(front != NULL){
                temp.push_back(front->val);
            }
            if(front == NULL){
                flag = !flag;
                
                if(q.size() > 0){
                    q.push(NULL);
                }
                
                res.push_back(temp);
                vector<int> t;
                temp = t;
            }else{
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
               
            }
        }
        
        int n = res.size();
        
        for(int i = 0; i < n; i++){
            if(i % 2 != 0){
                reverse(res[i].begin(), res[i].end());
            }
        }
        
        return res;
    }
};