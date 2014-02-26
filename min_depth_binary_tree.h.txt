/*
http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
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
#include <limits.h> 
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
            
        int left = minDepth(root->left);
        int right = minDepth(root->right); 
        
        if(left == 0 || right == 0)
            return right == 0 ? left + 1 : right + 1; 
        else
            return left < right ? left + 1 : right + 1;
    }
};