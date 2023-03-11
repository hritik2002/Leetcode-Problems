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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(vector<int> &arr,int l,int h){
        if(l>h)
            return NULL;
        int m=(l+h)/2;
        TreeNode* node = new TreeNode();
        node->val=arr[m];
        node->left=func(arr,l,m-1);
        node->right=func(arr,m+1,h);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        } 
        TreeNode* root=func(arr,0,arr.size()-1);
        return root;
    }
};