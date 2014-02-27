/*
problem: http://oj.leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows <= 0)
            return res;
            
        if(numRows == 1)
        {
            vector<int> tmp;
            tmp.push_back(1);
            res.push_back(tmp);
            return res;
        }
        
        res = generate(numRows - 1);
        int n = (int)res.size();
        int sz = (int)res[n-1].size();
        vector<int> row(sz+1, 1);
        for(int i=1;i<sz;i++)
            row[i] = res[n-1][i-1] + res[n-1][i];
        res.push_back(row);
        return res;
    }
};