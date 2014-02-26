/*
http://oj.leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* head=NULL, *tail=NULL;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1!= NULL && (l2 == NULL || l1->val < l2->val))
            {
                if(head == NULL)
                {
                    head = tail = l1;
                }
                else
                {
                    tail->next = l1;
                    tail = l1;
                }
                l1 = l1->next;
            }
            else
            {
                if(head == NULL)
                {
                    head = tail = l2;
                }
                else
                {
                    tail->next = l2;
                    tail = l2;
                }
                l2 = l2->next;
            }
        }
        return head;
    }
};