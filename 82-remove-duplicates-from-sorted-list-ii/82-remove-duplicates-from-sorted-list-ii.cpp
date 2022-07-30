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
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        while(head){
            if(head->next != NULL && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head = head->next;
                }
                if(head != NULL)head = head->next;
            }
            else{
                prev->next = head;
                prev = prev->next;
                head = head->next;
                prev->next = NULL;
            }
            
        }
        
        return dummy->next;
    }
};