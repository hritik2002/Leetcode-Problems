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
        
        Node* iterator = head, *next = NULL;
        
        while(iterator != NULL){
            next = iterator->next;
            Node* newNode = new Node(iterator->val);
            iterator->next = newNode;
            newNode->next = next;
            iterator = next;
        }
        
        iterator = head;
        
        while(iterator != NULL){
            next = iterator->next;
            
            if(iterator->random)
                next->random = iterator->random->next;
            
            iterator = next->next;
        }
        
        iterator = head;
        Node* copy_head = NULL, *copy_tail = NULL;
        
        while(iterator != NULL){
            next = iterator->next;
            
            if(copy_head == NULL){
                copy_head = next;
                copy_tail = next;
            
            }
            else {
                copy_tail->next = next;
                copy_tail = next;
            }
            
            iterator->next = next->next;
            iterator = next->next;
        }
        
        return copy_head;
    }
};