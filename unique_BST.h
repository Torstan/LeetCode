/*
http://oj.leetcode.com/problems/unique-binary-search-trees/
*/
#include <vector>
using std::vector;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 1;
        vector<int> num_bst(n + 1, 1);
        for(int i=2;i<=n;i++)
        {
            int s = 0;
            for(int k=0;k<i;k++)
                s += num_bst[k] * num_bst[i-1-k]; 
            num_bst[i] = s;
        }
        return num_bst[n];
    }
};