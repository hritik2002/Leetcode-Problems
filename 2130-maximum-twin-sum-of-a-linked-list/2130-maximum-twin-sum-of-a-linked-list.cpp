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
    int ans;
    ListNode* start;
    
    void getMaximumSum(ListNode* end_node){
        if(end_node == NULL)return ;
        
        getMaximumSum(end_node->next);
        ans = max(end_node->val + start->val, ans);
        start = start->next;
    
    }
    int pairSum(ListNode* head) {
       start = head;
    ans = 0;
        
        getMaximumSum(head);
        
        return ans;
    }
};