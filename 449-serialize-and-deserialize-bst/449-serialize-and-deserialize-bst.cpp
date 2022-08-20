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
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val) + ",";
        
        while(q.size()) {
            TreeNode* front = q.front();
            q.pop();
            
            if(front->left) {
                q.push(front->left);
                ans += to_string(front->left->val) + ",";
            }else ans += "#,";
            if(front->right) {
                q.push(front->right);
                ans += to_string(front->right->val) + ",";
            }else ans += "#,";
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0, size = data.length();
        if(size == 0) {
            return NULL;
        }
        queue<TreeNode*> q;
        string str = "";
        
        while(data[index] != ',') str += data[index++];
        index++;
        
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(index < size) {
            TreeNode* front = NULL;
            
            if(q.size()) {
                front = q.front();
                q.pop();
            }
            if(front == NULL) {
                index++;
                continue;
            }
            
            if(data[index] == '#') {
                index += 2;
                front->left = NULL;
            }else {
                str = "";
                
                while(data[index] != ',') str += data[index++];
                
                index++;
                front->left = new TreeNode(stoi(str)), q.push(front->left);
                
            } 
            
            if(index >= size)break;
            if(data[index] == '#') {
                front->right = NULL;
                index += 2;
            }else {
                str = "";
                
                while(data[index] != ',') str += data[index++];
                index++;
                
                front->right = new TreeNode(stoi(str)), q.push(front->right);
            }
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;