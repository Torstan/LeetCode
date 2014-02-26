/*
http://oj.leetcode.com/problems/maximum-subarray/
*/
#include<vector>
using std::vector;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0)
            return -1;
            
        vector<int> maxsubarr(n, 0);
        maxsubarr[0] = A[0];
        for(int i=1;i<n;i++)
        {
            maxsubarr[i] = maxsubarr[i-1] > 0 ? maxsubarr[i-1] + A[i] : A[i];
        }
        int max = -100000000;
        for(int i=0;i<n;i++)
        {
            if(maxsubarr[i] > max)
                max = maxsubarr[i];
        }
        return max;
    }
};