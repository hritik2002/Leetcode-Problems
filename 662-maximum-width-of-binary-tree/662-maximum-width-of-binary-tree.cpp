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
#define lli long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        lli prevMin = 0;
        lli maxWidth = 0;
        queue<pair<TreeNode*, lli>> queueNode;
        queueNode.push({root, 0});
        
        while(queueNode.size() > 0){
            lli size = queueNode.size();
            lli minNode = INT_MAX;
            pair<TreeNode*, lli> frontNode = queueNode.front();
            pair<TreeNode*, lli> backNode = queueNode.back();
            
            maxWidth = max(maxWidth, backNode.second - frontNode.second);
            for(lli i = 0; i < size; i++){
                pair<TreeNode*, lli> front = queueNode.front();
                queueNode.pop();
                
                if(front.first->left) {
                    lli colLevel = (front.second - prevMin)*2 + 1;
                    minNode = min(minNode, colLevel);
                    queueNode.push({front.first->left, colLevel});
                }
                if(front.first->right) {
                    lli colLevel = (front.second - prevMin)*2 + 2;
                    minNode = min(minNode, colLevel);
                    queueNode.push({front.first->right, colLevel});
                }
            }
            
            prevMin = minNode;
        }
                                   
        return maxWidth + 1;
         
    }
};