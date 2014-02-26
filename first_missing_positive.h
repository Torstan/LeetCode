/*
http://oj.leetcode.com/problems/first-missing-positive/
*/
#include <stdint.h>

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        //re-arrange the elements in the array such that A[i] = i + 1
        for(int i=0;i<n;i++)
        {
            int a = A[i];
            //put a in its place
            while(a > 0 && a <= n && A[a - 1] != a)
            {
                int tmp = A[a - 1];
                A[a - 1] = a;
                a = tmp;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(A[i] != i + 1)
                return (i+1);
        }
        return n+1;
    }
};