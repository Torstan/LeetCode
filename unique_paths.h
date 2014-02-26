/*
http://oj.leetcode.com/problems/unique-paths/
*/
#include <vector>
using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;
            
        //can be improved to use two arrays to save memory    
        vector<int> npath(m*n, 0);
        
        for(int x=0;x<n;x++)
            npath[x] = 1;
        for(int y=0;y<m;y++)
            npath[y*n] = 1;
            
        for(int y=1;y<m;y++)
        for(int x=1;x<n;x++)
        {
            npath[y*n + x] = npath[(y-1)*n + x] + npath[y*n + x-1]; 
        }
        return npath[m*n-1];
    }
};