/*
http://oj.leetcode.com/problems/insertion-sort-list/
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
    //keep two pointer, one is to save the result, the other is the unsorted list.
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* res = head;
        head = head->next;
        res->next = NULL;
        while(head != NULL)
        {
            ListNode* p = head->next;
            if(head->val <= res->val)
            {
                head->next = res;
                res = head;
            }
            else
            {
                ListNode* prev = res;
                for(ListNode* q = res; q && q->val < head->val; prev = q, q = q->next)
                {
                    ListNode* qq = q->next;
                    if(qq && qq->val >= head->val)
                    {
                        head->next = qq;
                        q->next = head;
                        break;
                    }
                }
                if(prev->next == NULL)
                {
                    prev->next = head;
                    head->next = NULL;
                }
            }
            head = p;
        }
        return res;
    }
};