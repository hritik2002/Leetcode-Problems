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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0 , length2 = 0 ;
        ListNode* temp = headA;
        while(temp){
            length1++;
            temp = temp->next;
        }
        temp = headB ;
        while(temp){
            length2++;
            temp = temp->next;
        }
        if(length1>length2){
            int n = length1 - length2 ;
            while(n--){
                headA = headA->next;
            }
            while(headA!=headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }else{
            int n = length2 - length1 ;
            while(n--){
                headB = headB->next;
            }
            while(headA!=headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }
    }
};