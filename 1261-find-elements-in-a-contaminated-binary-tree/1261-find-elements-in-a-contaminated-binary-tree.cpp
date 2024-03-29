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
class FindElements {
public:
    set<int> store;
    TreeNode* __root;
    FindElements(TreeNode* root) {
        __root = root;
        
        recoverTree(__root, 0);
    }
    
    bool find(int target) {
        return store.count(target);
    }
    void recoverTree(TreeNode* root, int parentValue) {
        if(root == NULL) {
            return;
        }
        
        root->val = parentValue;
        store.insert(root->val);
        
        recoverTree(root->left, root->val*2 + 1);
        recoverTree(root->right, root->val*2 + 2);
        
        return;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */