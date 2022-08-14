/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int maxLength = 0, n = root->children.size();
        for(int i = 0; i < n; i++) {
            int child = maxDepth(root->children[i]);
            maxLength = max(maxLength, child);
        }
        
        return maxLength + 1;
    }
};