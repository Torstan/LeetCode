/*
problem: http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* p = deleteDuplicates(head->next);
        head->next = p;
        if(p == NULL)
            return head;
        if(p->val == head->val)
        {
            //free(head); or delete head;
            return p;
        }
        else
        {
            return head;
        }
    }
};