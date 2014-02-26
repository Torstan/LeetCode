/*
http://oj.leetcode.com/problems/clone-graph/
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 #include <map>
 using std::map;
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode *> visit;
        return cloneGraph_r(node, visit);
    }
private:
    UndirectedGraphNode *cloneGraph_r(UndirectedGraphNode *node, map<int, UndirectedGraphNode *>& visit) {
        if(node == NULL)
            return NULL;
            
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        if(newnode == NULL)
            return NULL;

        visit[node->label] = newnode;
        
        int nb = (int)node->neighbors.size();
        newnode->neighbors.reserve(nb);
        for(int i=0;i<nb;i++)
        {
            UndirectedGraphNode* p = NULL;
            if(visit.find(node->neighbors[i]->label) == visit.end())
            {
                p = cloneGraph_r(node->neighbors[i], visit);
            }
            else
            {
                p = visit[node->neighbors[i]->label];
            }
            newnode->neighbors.push_back(p);
        }
        return newnode;
    }
};