/*
http://oj.leetcode.com/problems/rotate-image/
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = (int)matrix.size();
        for(int r=0;r<n/2;r++)
        {
            for(int i=r;i<n-1-r;i++)
            {
                //d=i-r
                int temp = matrix[r][i];
                matrix[r][i] = matrix[n-1-i][r];
                matrix[n-1-i][r] = matrix[n-1-r][n-1-i];
                matrix[n-1-r][n-1-i] = matrix[i][n-1-r];
                matrix[i][n-1-r] = temp;
            }
        }
    }
};