/*
http://oj.leetcode.com/problems/sort-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *merge_list(ListNode *head1, ListNode *head2)
{
    ListNode* head = NULL, *tail = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->val < head2->val)
        {
            if(tail != NULL)
            {
                tail->next = head1;
                tail = tail->next;
            }
            else
            {
                head = head1;
                tail = head;
            }
            head1 = head1->next;
        }
        else
        {
            if(tail != NULL)
            {
                tail->next = head2;
                tail = tail->next;
            }
            else
            {
                head = head2;
                tail = head;
            }
            head2 = head2->next;
        }
    }
    if(head1 == NULL)
    {
        while(head2 != NULL)
        {
            if(tail != NULL)
            {
                tail->next = head2;
                tail = tail->next;
            }
            else
            {
                head = head2;
                tail = head;
            }
            head2 = head2->next;
        }
    }
    
    if(head2 == NULL)
    {
        while(head1 != NULL)
        {
            if(tail != NULL)
            {
                tail->next = head1;
                tail = tail->next;
            }
            else
            {
                head = head1;
                tail = head;
            }
            head1 = head1->next;
        }
    }
    if(tail != NULL)
        tail->next = NULL;
    return head;
}

//split one list into 2 saperate lists
ListNode *split_list(ListNode *head)
{
    if(head == NULL)
        return NULL;
    ListNode *p = head;
    ListNode *prev = head;
    ListNode *mid = head;
    while(p != NULL)
    {
        p = p->next;
        if(p == NULL)
            break;
        prev = mid;
        mid = mid->next;
        p = p->next;
    }
    prev->next = NULL;
    return mid;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* mid = split_list(head);
        if(mid == head) //only one element
        {
            return head;
        }
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(mid);
        return merge_list(head1, head2);
    }
};
