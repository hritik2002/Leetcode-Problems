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
#define NOT_NEEDED 0
#define NEED_CAMERA 1
#define HAS_CAMERA 2
class Solution {
public:
    int ans;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return NOT_NEEDED;
        }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == NEED_CAMERA || right == NEED_CAMERA){
            ans++;
            return HAS_CAMERA;
        }
        else if(left == NOT_NEEDED && right == NOT_NEEDED) {
            return NEED_CAMERA;
        }
        else {
            return NOT_NEEDED;
        }
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;

        if(dfs(root) == NEED_CAMERA) {
            cout<<ans<<endl;
            ans++;
        }
        
        return ans;
        
    }
};