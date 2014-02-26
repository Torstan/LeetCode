/*
http://oj.leetcode.com/problems/single-number-ii/
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int res[32] = {0};
        for(int i=0;i<n;i++)
        {
            unsigned int a=*(unsigned int*)(&A[i]);
            int j=0;
            while(a > 0)
            {
                res[j] = (res[j] + a % 2) % 3;
                a /= 2;
                j++;
            }
        }
        int s = 0;
        for(int i=31;i>=0;i--)
        {
            if(res[i])
                s |= (1 << i);
        }
        return s;
    }
};