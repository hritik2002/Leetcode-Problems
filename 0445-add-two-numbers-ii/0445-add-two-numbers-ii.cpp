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
    ListNode* reverseLinkedList(ListNode* ll) {
        if(!ll->next) {
            return ll;
        }
        
        ListNode* lastNode = reverseLinkedList(ll->next);
        ll->next->next = ll;
        ll->next = NULL;
        
        return lastNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode* reverse1 = reverseLinkedList(l1);
        ListNode* reverse2 = reverseLinkedList(l2);
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        
        while(reverse1 && reverse2) {
            sum = reverse1->val + reverse2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            head->next = new ListNode(sum);
            head = head->next;
            reverse1 = reverse1->next;
            reverse2 = reverse2->next;
        }
        
        while(reverse1) {
            sum = reverse1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            head->next = new ListNode(sum);
            head = head->next;
            reverse1 = reverse1->next;
        }
        while(reverse2) {
            sum = reverse2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            head->next = new ListNode(sum);
            head = head->next;
            reverse2 = reverse2->next;
        }
        
        if(carry) {
            head->next = new ListNode(carry);
            head = head->next;
        }
        
        return reverseLinkedList(result->next);
    }
};

// reverse both ll
// add both ll
// reverse the resultant ll