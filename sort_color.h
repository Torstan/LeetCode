/*
problem: http://oj.leetcode.com/problems/sort-colors/
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int p = 0;
        int q = n-1;
        for(int i=0;i<=q;i++)
        {
            if(A[i] == 2)
            {
                if(i != q)
                {
                    std::swap(A[i], A[q]);
                    i--; //compare once again since A[i] has a new value
                }
                q--;
            }
            else if(A[i] == 0)
            {
                if(i != p)
                {
                    std::swap(A[i], A[p]);
                    i--; //compare once again since A[i] has a new value
                }
                p++;
            }
        }
    }
};