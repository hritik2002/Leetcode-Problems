/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head;
        
        int index = 0;
        Node* init_head = head;
        map<int, Node*> int_to_node;
        map<Node*, Node*> node_to_node;
        
        Node* newHead  = new Node(head->val);
        // int_to_node[index] = head->random;
        // index++;
        node_to_node[head] = newHead;
        node_to_node[NULL] = NULL;
        
        Node* tail = newHead;
        head = head->next;
        
        while(head){
            tail->next = new Node(head->val);
            // int_to_node[index] = head->random;
            node_to_node[head] = tail->next;
            // index++;
            
            head = head->next;
            tail = tail->next;
        }
        
        tail = newHead;
        head = init_head;
        index = 0;
        
        while(tail){
            tail->random = node_to_node[head->random];
            tail = tail->next;
            head = head->next;
            // index++;
        }
        
        return newHead;
    }
};