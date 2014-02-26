/*
http://oj.leetcode.com/problems/n-queens/
*/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > final_res;
        if(n == 0)
            return final_res;
            
        vector<int> row;
        row.push_back(0);

        while(!row.empty())
        {
            if(is_solution(row, n))
            {
                add_to_result(row, final_res);
                if(back_tracking(row, n) != 0)
                {
                    return final_res;
                }
            }
            else
            {
                int pos = pick_column(row, n, 0);
                if(pos == -1) //no position found
                {
                    if(back_tracking(row, n) != 0)
                    {
                        return final_res;
                    }
                }
                else
                    row.push_back(pos);
            }
        }
        return final_res;
    }
private:

    void add_to_result(const vector<int> &row, vector<vector<string> >& final_res)
    {
        int n = (int)row.size();
        vector<string> sol;
        sol.reserve(n);
        for(int i=0;i<n;i++)
        {
            string s(n, '.');
            s[row[i]] = 'Q';
            sol.push_back(s);
        }
        final_res.push_back(sol);
    }
    //return -1 if no valid position
    int pick_column(const vector<int>& row, int n, int start)
    {
        int sz = (int)row.size();
        if(sz >= n)  //a solution
            return -1;
           
        if(sz == 0)  
            return start < n ? start : -1;
            
        for(int i=start;i<n;i++)
        {
            int j = 0;
            for(j=0;j<sz;j++)
            {
                if(i == row[j] || (row[j] - j == i - sz) || (row[j] + j == i + sz))
                {
                    break;
                }
            }
            if(j == sz)
                return i;
        }
        return -1;
    }
    
    int is_solution(const vector<int>& row, int n)
    {
        int sz = (int)row.size();
        return sz == n ? 1 : 0;
    }
    
    //if current node is the a solution or the dead end, we back tracking to a previous location
    //return 0 for success, -1 for cann't back track
    int back_tracking(vector<int>& row, int n)
    {
        int pos = -1;
        //more than one elements
        while(!row.empty())
        {
            int last = row.back();
            row.pop_back();
            pos = pick_column(row, n, last + 1);
            if(pos != -1)
                break;
        }
        if(pos == -1)
            return -1;
        row.push_back(pos);
        return 0;
    }
};