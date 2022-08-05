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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if(root == NULL) {
            return res;
        }
        
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        
        while(nodeQueue.size() > 0) {
            int size = nodeQueue.size();
            vector<int> rowNodes;
            
            for(int i = 0; i < size; i++) {
                Node* front = nodeQueue.front();
                nodeQueue.pop();
                int childrenSize = front->children.size();
                rowNodes.push_back(front->val);
                
                for(int j = 0; j < childrenSize; j++) {
                    nodeQueue.push(front->children[j]);
                }
            }
            
            res.push_back(rowNodes);
        }
        
        return res;
    }
};