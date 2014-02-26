/*
http://oj.leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        while(p != NULL)
        {
            p = p->next;
            head = head->next;
            if(p != NULL)
                p = p->next;
            else
                break;
            if(p == head)
                return true;
        }
        return false;
    }
};