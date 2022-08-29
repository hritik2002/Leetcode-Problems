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

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int n = lists.size();
        
        for(int i = 0; i < n; i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        
        if(!pq.size()) {
            return NULL;
        }
        
        head = pq.top();
        pq.pop();
        
        if(head->next) {
            pq.push(head->next);
        }
        
        ListNode* tail = head;
        
        while(pq.size()) {
            tail -> next = pq.top();
            pq.pop();
            tail = tail -> next;
            
            if(tail -> next) {
                pq.push(tail -> next);
            }
        }
        
        return head;
    }
};