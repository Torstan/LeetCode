/*
http://oj.leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode *head) {
        ListNode* odd = split(head);
        merge(head, odd);
    }
    
    ListNode* split(ListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* q = head, *p=head, *prevp = NULL;
        while(q != NULL)
        {
            q = q->next;
            prevp = p;
            p = p->next;
            if(q == NULL)
                break;
            q = q->next;
        }
        if(prevp != NULL)
            prevp->next = NULL;
            
        ListNode* oddrev = NULL; //odd elements in reverse order
        ListNode* pp = p;
        while(pp != NULL)
        {
            ListNode* next = pp->next;
            pp->next = oddrev;
            oddrev = pp;
            pp = next;
        }
        return oddrev;
    }
    
    void merge(ListNode *even, ListNode *odd)
    {
        if(odd == NULL)
            return;
        ListNode* p = odd, *q = even;
        while(p != NULL)
        {
            ListNode* qnext = q->next;
            ListNode* pnext = p->next;
            q->next = p;
            p->next = qnext;
            p = pnext;
            q = qnext;
        }
    }
};