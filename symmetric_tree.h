/*
problem: http://oj.leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode *root) {
        vector<int> left, right;
        child_traversal_inorder(root, left, 0);
        child_traversal_inorder(root, right, 1);
        int n = (int)left.size();
        for(int i=0;i<n;i++)
        {
            if(left[i] != right[i])
                return false;
        }
        
        left.clear();
        right.clear();
        
        child_traversal(root, left, 0);
        child_traversal(root, right, 1);
        n = (int)left.size();
        for(int i=0;i<n;i++)
        {
            if(left[i] != right[i])
                return false;
        }
        return true;
    }
    
    int child_traversal_inorder(const TreeNode *root, vector<int>& res, int direction)
    {
        if(root == NULL)
            return 0;
        
        if(direction == 0) // left child first
        {
            child_traversal_inorder(root->left, res, direction);
            res.push_back(root->val);
            child_traversal_inorder(root->right, res, direction);
        }
        else
        {
            child_traversal_inorder(root->right, res, direction);
            res.push_back(root->val);
            child_traversal_inorder(root->left, res, direction);
        }
        return 0;
    }
    
    int child_traversal(const TreeNode *root, vector<int>& res, int direction)
    {
        if(root == NULL)
            return 0;
        
        res.push_back(root->val);
        if(direction == 0) // left child first
        {
            child_traversal(root->left, res, direction);
            child_traversal(root->right, res, direction);
        }
        else
        {
            child_traversal(root->right, res, direction);
            child_traversal(root->left, res, direction);
        }
        return 0;
    }
};