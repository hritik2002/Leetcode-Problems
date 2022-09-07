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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* prev = head;
        ListNode* back = NULL;
        head = head->next;
        ListNode* tail = head;
        
        while(tail) {
            prev->next = tail->next;
            ListNode* next = tail->next;
            tail->next = prev;
            if(back) {
                back->next = tail;
            }
            
            back = prev;
            prev = next;
            if(next) {
                tail = next->next;
            }else {
                break;
            }
        }
        
        return head;
    }
};