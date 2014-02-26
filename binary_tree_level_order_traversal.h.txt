/*
http://oj.leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        map<int, vector<int> >res;
        levelOrder(root, 0, res);
        int n = (int)res.size();
        vector<vector<int> > final_res;
        final_res.reserve(n);
        map<int, vector<int> >::const_iterator iter = res.begin();
        for(;iter != res.end();iter++)
        {
            final_res.push_back(iter->second);
        }
        return final_res;
    }
private:
    void levelOrder(const TreeNode *root, int level, map<int, vector<int> >&res)
    {
        if(root == NULL)
            return;
        if(res.find(level) == res.end())
        {
            vector<int> v;
            v.push_back(root->val);
            res[level] = v;
        }
        else
        {
            res[level].push_back(root->val);
        }
        
        levelOrder(root->left, level + 1, res);
        levelOrder(root->right, level + 1, res);
    }
};