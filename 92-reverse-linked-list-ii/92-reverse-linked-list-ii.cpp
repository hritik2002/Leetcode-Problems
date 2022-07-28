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
    ListNode* reverse(ListNode* head, int end){
        if(end == 0 || head->next == NULL){
            return head;
        }
        
        ListNode* reversed_head = reverse(head->next, end-1);
        
        head->next->next = head;
        head->next = NULL;
        
        return reversed_head;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newHead = NULL;
        ListNode* initial_head = head;
        int count = left;
        
        while(count > 1 && head){
            newHead = head;
            head = head->next;
            count--;
        }
        
        ListNode* head_subList = head;
        
        ListNode* attach_to_end = head;
        count = right - left + 1;
        
        while(attach_to_end && count--){
            attach_to_end = attach_to_end->next;
        }
        
        ListNode* prev = head;
        
        if(newHead){
            newHead->next = reverse(head, right - left);
            newHead = newHead->next;
            prev->next = attach_to_end;
            
            return initial_head;
        }else{
            newHead = reverse(head, right - left);
            if(attach_to_end){
                prev->next = attach_to_end;
            }
            return newHead;
        }
      
        
    }
};