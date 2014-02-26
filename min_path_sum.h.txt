/*
http://oj.leetcode.com/problems/minimum-path-sum/
*/
#include <algorithm>
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = (int)grid.size();
        if(m <= 0)
            return 0;
        int n = 0;
        vector<vector<int> > cost;
        cost.reserve(m);
        for(int i=0;i<m;i++)
        {
            n = (int)grid[i].size();
            if(n <= 0)
                return 0;
            cost.push_back(grid[i]);
        }
        cost[0][0] = grid[0][0];
        for(int i=1;i<n;i++)
            cost[0][i] = cost[0][i-1] + grid[0][i];
        for(int i=1;i<m;i++)
            cost[i][0] = cost[i-1][0] + grid[i][0];
            
        for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            cost[i][j] = std::min(cost[i-1][j], cost[i][j-1]) + grid[i][j];
            
        return cost[m-1][n-1];
    }
};