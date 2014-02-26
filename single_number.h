/*
http://oj.leetcode.com/problems/single-number/
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int s=0;
        for(int i=0;i<n;i++)
        {
            s ^= A[i];
        }
        return s;
    }
};