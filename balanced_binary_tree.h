/*
http://oj.leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalanced(root, height);
    }
private:
    bool isBalanced(TreeNode *root, int & height)
    {
        if(root == NULL)
        {
            height = 0;
            return true;
        }
        int left_height = 0;
        if(!isBalanced(root->left, left_height))
            return false;
        int right_height = 0;
        if(!isBalanced(root->right, right_height))
            return false;
        
        int max = left_height > right_height ? left_height : right_height;
        int min = left_height < right_height ? left_height : right_height;
        
        height = max + 1;
        return max - min <= 1 ? true : false;
    }
};