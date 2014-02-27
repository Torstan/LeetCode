/*
problem: http://oj.leetcode.com/problems/remove-element/
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n <= 0)
            return 0;
            
        int m=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(A[i] == elem)
            {
                std::swap(A[i], A[m]);
                m--;
            }
        }
        return m+1;
    }
};