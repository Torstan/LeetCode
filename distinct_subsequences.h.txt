/*
http://oj.leetcode.com/problems/distinct-subsequences/
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = (int)S.size();
        int n = (int)T.size();
        vector<vector<int> > matrix;
        matrix.reserve(n + 1);
        for(int i=0;i<=n;i++)
        {
            vector<int> v(m + 1, 1);
            matrix.push_back(v);
        }
        for(int i=1;i<=n;i++)
            matrix[i][0] = 0;
            
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(S[j-1] == T[i-1])
                    matrix[i][j] = matrix[i-1][j-1] + matrix[i][j-1];
                else
                    matrix[i][j] = matrix[i][j-1];
            }
        }
        return matrix[n][m];
    }
};