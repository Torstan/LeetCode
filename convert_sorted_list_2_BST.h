/**
 *http://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 *author: agoodcoder
 *date: 2014.1.2
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ListNode* SplitMiddle(ListNode *head)
 {
    if(head == NULL)
        return NULL;
    ListNode* p = head;
    ListNode* prev = head;
    while(p!=NULL)
    {
        p = p->next;
        if(p==NULL)
        {
            break;   
        }
        prev = head;
        head = head->next;
        p = p->next;
    }
    prev->next = NULL;
    return head;
}
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)  //empty
            return NULL;
        ListNode* mid = SplitMiddle(head);
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        if(node == NULL)
            return NULL;
        TreeNode* left = NULL;
        if(mid != head)  //more than one element
            left = sortedListToBST(head);
        TreeNode* right = sortedListToBST(mid->next);
        node->val = mid->val;
        node->left = left;
        node->right = right;
        return node;
    }
};