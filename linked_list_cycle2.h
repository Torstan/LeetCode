/*
problem: http://oj.leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        const ListNode* collide = detectCollide(head);
        if(collide == NULL)
            return NULL;
        const ListNode *p = FindCollide(head, collide);
        return (ListNode *)p;
    }
    //retrun NULL if no collide point
    const ListNode *detectCollide(const ListNode *head)
    {
        if(head == NULL)
            return NULL;
        const ListNode*p = head;
        const ListNode* p2 = head;
        while(p2 != NULL)
        {
            p = p->next;
            p2 = p2->next;
            if(p2 == NULL)
                break;
            p2 = p2->next;
            if(p == p2)
                break; 
        }
        return p2;
    }
    //assume head and collide are both valid
    const ListNode *FindCollide(const ListNode *head, const ListNode *collide)
    {
        const ListNode*p = head;
        const ListNode*q = collide;
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};