/*
http://oj.leetcode.com/problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        return addTwoNumbers(l1, l2, carry);
    }
private:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if(l1 == NULL && l2 == NULL && carry == 0)
        {
            return NULL;
        }
        int s = l1 == NULL ? 0 : l1->val;
        s += (l2 == NULL ? 0 : l2->val);
        s += carry;
        ListNode* node = new ListNode(s%10);
        if(node == NULL)
            return NULL;
        node->next = addTwoNumbers(l1 != NULL ? l1->next : NULL, l2 != NULL ? l2->next : NULL, s/10);
        return node;
    }
};