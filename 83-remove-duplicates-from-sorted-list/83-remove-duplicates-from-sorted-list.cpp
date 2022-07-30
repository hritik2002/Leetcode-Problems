/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return head;
        
        int prev = head->val;
        ListNode* prev_node = head, *iterator = head;
        iterator = iterator->next;
        
        while(iterator){
            if(prev == iterator->val){
                prev_node->next = iterator->next;
            }else prev = iterator->val, prev_node = iterator;
            
            iterator = iterator->next;
        }
        
        return head;
    }
};