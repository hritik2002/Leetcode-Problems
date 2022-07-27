/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool> store;
        
        while(head){
            if(store[head])return head;
            
            store[head] = true;
            head = head->next;
        }
        
        return NULL;
    }
};