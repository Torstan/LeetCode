/*
*http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
*/

#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorderTrav(root, res);
        return res;
    }
private:
    void copy_vector(const vector<int>& vec, vector<int>& res) 
    {
        int num = (int)vec.size();
        for(int i=0;i<num;i++)
            res.push_back(vec[i]);
    }
    
    int postorderTrav(TreeNode *root, vector<int>& res)
    {
        if(root == NULL)
            return -1;
     
        vector<int> left;
        vector<int> right;
        postorderTrav(root->left, left);
        postorderTrav(root->right, right);
        
        int num = (int)left.size() + (int)right.size() + 1;
        res.clear();
        res.reserve(num);
        copy_vector(left, res);
        copy_vector(right, res);
        res.push_back(root->val);
        return 0;  
    }
};