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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }else if(l2 == NULL) {
            return l1;
        }
        
        int sum = 0, carry = 0;
        ListNode* head = NULL, *tail = NULL;
        
        while(l1 && l2) {
            if(head == NULL) {
                sum = l1->val + l2->val;
                carry = sum / 10;
                sum = sum % 10;
                head = new ListNode(sum);
                tail = head;
            }else {
                sum = l1->val + l2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            l1 = l1->next;
        }
        
        while(l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            l2 = l2->next;
        }
        
        if(carry) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        
        tail->next = NULL;
        
        return head;
    }
};