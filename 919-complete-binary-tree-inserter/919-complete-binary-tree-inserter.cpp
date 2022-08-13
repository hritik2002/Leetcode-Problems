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
class CBTInserter {
public:
    TreeNode* __root = NULL;
    
    CBTInserter(TreeNode* root) {
        __root = root;
    }
    
    int insert(int val) {
        queue<TreeNode*> nodes;
        nodes.push(__root);
        TreeNode* curr = __root;
        
        while(nodes.size()) {
            curr = nodes.front();
            nodes.pop();
            
            if(curr->left == NULL) {
                curr->left = new TreeNode(val);
                break;
            }
            if(curr->right == NULL) {
                curr->right = new TreeNode(val);
                break;
            }
            
            if(curr->left) {
                nodes.push(curr->left);
            }
            if(curr->right) {
                nodes.push(curr->right);
            }
        }
        
        return curr->val;
    }
    
    TreeNode* get_root() {
        return __root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */