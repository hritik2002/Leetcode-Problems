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
    int time = 0;
    set<int>st;
    void findTarget(TreeNode* root, int &start, vector<TreeNode*> &nodes) {
        if(root == NULL) {
            return;
        }
        if(start == root->val) {
            st.insert(root->val);
            infect(root->left, 1);
            infect(root->right, 1);
            
            
            for(int i = nodes.size() - 1; i >= 0; i--) {
                infect(nodes[i], nodes.size() - i);
                st.insert(nodes[i]->val);
            }
            
            return;
        }
        
        nodes.push_back(root);
        findTarget(root->left, start, nodes);
        findTarget(root->right, start,nodes);
        nodes.pop_back();
    }
    void infect(TreeNode* root, int level) {
        if(root == NULL || st.count(root->val)) return;
        
        if(time < level){
            time = level;
        }
        
        st.insert(root->val);
        infect(root->left, level + 1);
        infect(root->right, level + 1);
        
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*> nodes;
        findTarget(root, start, nodes);
        
        return time;
    }
};