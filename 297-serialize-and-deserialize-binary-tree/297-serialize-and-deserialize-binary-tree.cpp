/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void getSerialize(TreeNode* root, string &ans) {
        if(root == NULL) {
            ans += "#,";
            
            return;
        }
        
        ans += to_string(root->val) + ",";
        getSerialize(root->left, ans);
        getSerialize(root->right, ans);
        
        return;
    }
    TreeNode* getDeserialize(string data, int &index, int size) {
        if(index >= size) {
            return NULL;
        }
        if(data[index] == '#') {
            index += 2;
            
            return NULL;
        }
        
        string str = "";
        while(data[index] != '#' && data[index] != ',') {
            str += data[index++];
        }
        if(data[index] == '#')
            index += 2;
        else index++;
        if(index >= size) {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(str));
        root->left = getDeserialize(data, index, size);
        root->right = getDeserialize(data, index, size);
        
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        getSerialize(root, ans);
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) {
            return NULL;
        }
        
        int index = 0, size = data.length();
        
        return getDeserialize(data, index, size);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));