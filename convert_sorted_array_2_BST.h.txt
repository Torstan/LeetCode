/*
http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = (int)num.size();
        if(n == 0)
            return NULL;
        int mid = (n-1)/2;
        TreeNode *node = new TreeNode(num[mid]);
        vector<int> left(num.begin(), num.begin()+mid);
        vector<int> right(num.begin()+mid+1, num.end());
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }
};