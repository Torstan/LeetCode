/*
http://oj.leetcode.com/problems/copy-list-with-random-pointer/
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode *create_node(int x)
{
    RandomListNode* node = (RandomListNode*)malloc(sizeof(RandomListNode));
    if(node == NULL)
        return NULL;
    node->label = x;
    node->next = NULL;
    node->random = NULL;
    return node;
}
    
#include <map>
using std::map;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> old2new;
        RandomListNode* res = NULL, *tail=NULL;
        RandomListNode *p = head;
        while(p != NULL)
        {
            RandomListNode* node = NULL;
            if(old2new.find(p) != old2new.end()) //has created before
            {
               node = old2new[p];
            }
            else
            {
                node = create_node(p->label);
                if(node == NULL)
                    return res;
                old2new[p] = node;
            }
            
            if(res == NULL)
            {
                res = node;
                tail = node;
            }
            else
            {
                tail->next = node;
            }
            
            if(p->random != NULL)
            {
                if(old2new.find(p->random) != old2new.end())
                {
                    node->random = old2new[p->random];
                }
                else
                {
                    RandomListNode* node_r = create_node(p->random->label);
                    if(node_r == NULL)
                        return res;
                    node->random = node_r;
                    old2new[p->random] = node_r;
                }
            }
            p = p->next;
            tail = node;
        }
        return res;
    }
};