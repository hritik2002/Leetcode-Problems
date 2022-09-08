/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neivector<bool> visited();ghbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* cloneNode;
        
        if(node == NULL) {
            return cloneNode;
        }

        Node* root = NULL;
        queue<Node*> q;
        q.push(node);
        set<int> st;
        map<Node*, Node*> old_to_new;
        st.insert(node->val);

        while(q.size()) {
            auto front = q.front();
            
            // add new address against old address for specific value
            if(!old_to_new[front]) {
                old_to_new[front] = new Node(front->val);
            }
            
            cloneNode = old_to_new[front];

            if(root == NULL) {
                root = cloneNode;
            }

            q.pop();
            
            for(auto neighbor : front->neighbors) {
                
                if(!st.count(neighbor->val)) {
                    // mark visited
                    st.insert(neighbor->val);
                    
                    // add new address against old address for specific value
                    old_to_new[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                
                cloneNode->neighbors.push_back(old_to_new[neighbor]);
            }
        }
        
        return root;
    }
};