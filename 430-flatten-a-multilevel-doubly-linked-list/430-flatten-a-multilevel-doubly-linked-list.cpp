/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)return head;
        
        Node* init_head = head;
        
        while(head != NULL){
            if(head->child != NULL){
                Node* next = head->next;
                head->next = flatten(head->child);
                head->next->prev = head;
                head->child = NULL;
                
                while(head && head->next != NULL)head = head->next;
                
                head->next = next;
                
                if(next)
                    next->prev = head;
                
            }
            
            head = head->next;
        }
        
        return init_head;
    }
};