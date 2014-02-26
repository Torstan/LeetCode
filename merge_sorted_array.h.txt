/*
http://oj.leetcode.com/problems/merge-sorted-array/
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int t = m + n -1;
        int sa = m - 1;
        int sb = n - 1;
        while(t >= 0)
        {
            if(sa >= 0 && sb >= 0)
            {
                if(A[sa] > B[sb])
                {
                    A[t--] = A[sa--];
                }
                else
                {
                    A[t--] = B[sb--];
                }
            }
            else if(sa < 0 && sb >= 0)
            {
                A[t--] = B[sb--];
            }
            else if(sa >=0 && sb < 0)
            {
                A[t--] = A[sa--];
            }
            else
                break;
        }
    }
};