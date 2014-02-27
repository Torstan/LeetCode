/*
problem: http://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL)
            return res;
            
        queue<TreeNode*> Q; 
        Q.push(root);
        Q.push(NULL); //end of this level
        stack<vector<int> > S; 
        vector<int> level;
        while(!Q.empty())
        {
            TreeNode *q = Q.front();
            Q.pop();
            if(q == NULL)
            {
                S.push(level);
                if(Q.size() > 0) //has something in the queue
                {
                    Q.push(NULL);
                }
                level.clear();
            }
            else
            {
                level.push_back(q->val);
                if(q->left != NULL)
                    Q.push(q->left);
                if(q->right != NULL)
                    Q.push(q->right);
            }
        }
        int sz = (int)S.size();
        res.reserve(sz);
        for(int i=0;i<sz;i++)
        {
            res.push_back(S.top());
            S.pop();
        }
        return res;
    }
};