/*
problem: http://oj.leetcode.com/problems/gray-code/
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n == 0)
        {
            res.push_back(0);
            return res;
        }
        if(n == 1)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        vector<int> res2 = grayCode(n-1);
        int m = (int)res2.size();
        res.reserve(m * 2);
        for(int i=0;i<m;i++)
            res.push_back(res2[i]);
        for(int i=m-1;i>=0;i--)
            res.push_back(res2[i] | (1<<(n-1)));
        return res;
    }
};