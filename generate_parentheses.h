/*
problem: http://oj.leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    vector<string> generateParentheses(int n) {
        const string empty("");
        vector<string> res;
        if(n <= 0)
        {
            res.push_back(empty);
            return res;
        }
        
        vector<vector<string> > tmp;
        tmp.reserve(n);
        
        for(int i=0;i<n;i++)
            tmp.push_back(generateParentheses(i));
            
        for(int i=0;i<n;i++)
        {
            int m1 = (int)tmp[n-1-i].size();
            int m2 = (int)tmp[i].size();
            for(int j=0;j<m1;j++)
            for(int k=0;k<m2;k++)
            {
                string s("(");
                if(!(m1 == 1 && tmp[n-1-i][0] == empty))
                {
                    s+=tmp[n-1-i][j];
                }
                s+=")";
                
                if(!(m2 == 1 && tmp[i][0] == empty))
                {
                    s+=tmp[i][k];
                }
                res.push_back(s);
            }
        }
        return res;
    }
};