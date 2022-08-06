/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL) {
            return root;
        }
        
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        
        while(nodeQueue.size() > 0){
            int size = nodeQueue.size();
            
            for(int i = 0; i < size; i++){
                Node* front = nodeQueue.front();
                nodeQueue.pop();
                
                if(i == size - 1) {
                    front->next = NULL;
                }else{
                    front->next = nodeQueue.front();
                }
                
                if(front->left) {
                    nodeQueue.push(front->left);
                }
                if(front->right) {
                    nodeQueue.push(front->right);
                }
            }
        }
        
        return root;
        
    }
};