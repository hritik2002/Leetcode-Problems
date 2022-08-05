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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || getIsSymmetric(root->left, root->right);
    }
    
    bool getIsSymmetric(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL)return true;
        if(left == NULL || right == NULL)return false;
        
        if(left->val != right->val)
            return false;
        
        return getIsSymmetric(left->left, right->right) && getIsSymmetric(left->right, right->left);
    }
    
    
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL)return true;
        
        
//         queue<TreeNode*> nodeQueue;
//         nodeQueue.push(root);
//         nodeQueue.push(NULL);
//         vector<int> rowNodes;
        
//         while(nodeQueue.size()){
//             TreeNode* front = nodeQueue.front();
//             nodeQueue.pop();
            
//             if(front == NULL){
//                 if(nodeQueue.size() > 0){
//                     nodeQueue.push(NULL);
//                 }
                
//                 int n = rowNodes.size();
//                 int i = 0, j = n - 1;
                
//                 while(i <= j){
//                     if(rowNodes[i] != rowNodes[j])
//                         return false;
//                     i++;
//                     j--;
//                 }
                
//                 vector<int> temp;
//                 rowNodes = temp;
//             }else{
//                 if(front->left){
//                     nodeQueue.push(front->left);
//                     rowNodes.push_back(front->left->val);
//                 }else{
//                     rowNodes.push_back(INT_MIN);
//                 }
//                 if(front->right){
//                     nodeQueue.push(front->right);
//                     rowNodes.push_back(front->right->val);
//                 }else{
//                     rowNodes.push_back(INT_MIN);
//                 }
//             }
//         }
        
//         return true;
//     }
};