/*
http://oj.leetcode.com/problems/permutations/
*/
#include <deque>
#include <algorithm>
using std::deque;

void transform(const deque<int> &deq, vector<int>& vec)
{
    int n = (int)deq.size();
    vec.clear();
    vec.reserve(n);
    deque<int>::const_iterator iter = deq.begin();
    for(;iter != deq.end();iter++)
    {
        vec.push_back(*iter);
    }
}

class Solution {
public:
    //assume the integers are different
    vector<vector<int> > permute(vector<int> &num) {
        deque<int> deq;
        deq.assign(num.begin(), num.end());
        vector<deque<int> >res;
        permute(deq, res);
        
        vector<vector<int> > final_res;
        int n = (int)res.size();
        final_res.reserve(n);
        for(int i=0;i<n;i++)
        {
            vector<int> vec;
            transform(res[i], vec);
            final_res.push_back(vec);
        }
        return final_res;
    }
private:
    void permute(deque<int> &num, vector<deque<int> >&res)
    {
        int n = (int)num.size();
        if(n == 0) //base case
        {
            deque<int> dq;
            res.push_back(dq);
            return;
        }
        for(int i=0;i<n;i++)
        {
            std::swap(num[0], num[i]);
            deque<int> sub_deq;
            sub_deq.assign(num.begin()+1, num.end());
            vector<deque<int> > sub_res;
            permute(sub_deq, sub_res);
            int sub_sz = (int)sub_res.size();
            for(int j=0;j<sub_sz;j++)
            {
                sub_res[j].push_front(num[0]);
                res.push_back(sub_res[j]);
            }
            std::swap(num[0], num[i]);
        }
    }
};