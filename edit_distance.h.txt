/*
http://oj.leetcode.com/problems/edit-distance/
*/
#include <vector>
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size() + 1;
        int n = (int)word2.size() + 1;

        vector<int> edist(m*n, 0);
        for(int i=0;i<m;i++)
            edist[i] = i;
        for(int j=0;j<n;j++)
            edist[j*m] = j;
        
        for(int j=1;j<n;j++)
        for(int i=1;i<m;i++)
        {
            int min_op = edist[(j-1)*m + i-1] + 1;
            if(word1[i-1] == word2[j-1])
                min_op--;
            if(min_op > edist[(j-1)*m + i])
                min_op = edist[(j-1)*m + i] + 1;
            if(min_op > edist[j*m + i-1])
                min_op = edist[j*m + i-1] + 1;
            edist[j*m + i] = min_op;
        }
        return edist[m*n-1];
    }
};