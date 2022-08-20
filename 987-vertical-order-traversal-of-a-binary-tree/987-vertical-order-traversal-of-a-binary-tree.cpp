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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> verticalLevelNodes;
        
        queue<pair<TreeNode*, int>> queueNode;
        queueNode.push({root, 0});
        
        while(queueNode.size() > 0) {
            int size = queueNode.size();
            map<int, vector<int>> rowNodes;
            
            for(int i = 0; i < size; i++) {
                pair<TreeNode*, int> front = queueNode.front();
                queueNode.pop();
                rowNodes[front.second].push_back(front.first->val);
                int level = front.second;
                
                if(rowNodes[front.second].size() > 1) {
                    sort(rowNodes[front.second].begin(), rowNodes[front.second].end());
                }
                
                if(front.first->left) {
                    queueNode.push({front.first->left, level - 1});
                }
                if(front.first->right) {
                    queueNode.push({front.first->right, level + 1});
                }
            }
            
            for(auto row : rowNodes) {
                for(auto val : row.second) {
                    verticalLevelNodes[row.first].push_back(val);
                }
            }
            
        }
        
        vector<vector<int>> res;
        
        for(auto verticalLevel : verticalLevelNodes) {
            res.push_back(verticalLevel.second);
        }
        
        return res;
    }
};