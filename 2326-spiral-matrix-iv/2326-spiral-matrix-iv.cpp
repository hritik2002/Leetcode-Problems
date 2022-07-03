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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int row_start = 0, col_start = 0, row_end = m, col_end = n;
        vector<vector<int>>mat(m,vector<int>(n,-1));
        while(head && m>0 && n>0){
            int i = row_end-m, j = col_end-n ;
            while(head && j<n){
                mat[i][j] = head->val;
                j++;
                head = head->next ;
            }
            j--;
            i++;
            if(!head)break;
            while(head && i<=m-1){
                mat[i][j] = head->val;
                i++;
                head = head->next ;
            }
            i--;
            j--;
            m--;
            if(!head)break;
            while(head && j>=col_end-n){
                mat[i][j] = head->val;
                j--;
                head = head->next ;
            }
            j++;
            i--;
            if(!head)break;
            while(head && i>=row_end-m){
                mat[i][j] = head->val;
                i--;
                head = head->next ;
            }
            i++;
            n--;
        }
        return mat;
    }
};