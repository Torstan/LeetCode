/*
problem: oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0)
            return 0;
        
        int m = 1;
        for(int i=1;i<n;i++)
        {
            if(A[m-1] != A[i])
            {
                std::swap(A[m], A[i]);
                m++;
            }
        }
        return m;
    }
};