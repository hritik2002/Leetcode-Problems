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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0 ;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        int kEnd = len-k ;
        temp = head;
        while(k>1&&temp){
            k--;
            temp = temp->next ;
        }
        ListNode* first = temp ;
        temp = head;
        while(kEnd>=1&&temp){
            temp = temp->next ;
            kEnd--;
        }
        // cout<<first->val<<" "<<temp->val<<endl;
        int swap = temp->val;
        temp->val = first->val;
        first->val = swap ;
        return head;
        
    }
};