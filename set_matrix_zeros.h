/*
problem: http://oj.leetcode.com/problems/set-matrix-zeroes/
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int nr = matrix.size();
        if(nr == 0)
            return;
        int nc = matrix[0].size();
        if(nc == 0)
            return;
            
        vector<int> row(nr, 0);
        vector<int> col(nc, 0);
        
        for(int i=0;i<nr;i++)
        for(int j=0;j<nc;j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
        for(int i=0;i<nr;i++)
        {
            if(row[i] == 1)
            {
                for(int j=0;j<nc;j++)
                    matrix[i][j] = 0;
            }
        }
        for(int j=0;j<nc;j++)
        {
            if(col[j] == 1)
            {
                for(int i=0;i<nr;i++)
                    matrix[i][j] = 0;
            }
        }
    }
};