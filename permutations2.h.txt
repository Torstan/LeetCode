/*
http://oj.leetcode.com/problems/permutations-ii/
*/
#include <algorithm>

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        res.push_back(num);
        while(next_permutation(num) == 0)
        {
            res.push_back(num);
        }
        return res;
    }
private:
    //return 0 if it has next permutation,
    //return -1 for reaching the end
    int next_permutation(vector<int> &num)
    {
        int n = (int)num.size();
        if(n <= 1)
            return -1;
        
        int j = 0,max = -100000;
        for(j=n-1;j>=0;j--)
        {
            if(max > num[j])
                break;
            else
                max = num[j];
        }
        if(j < 0)  //in desceding order, i.e. the final permutation
            return -1;
        
        int min = 100000, mini = 0;
        for(int i=n-1;i>j;i--)
        {
            if(num[i] > num[j])
            {
                if(num[i] < min)
                {
                    min = num[i];
                    mini = i;
                }
            }
        }
        //find two elements, indices at mini, and j
        std::swap(num[mini], num[j]);
        std::sort(num.begin()+j+1, num.end());
        return 0;
    }
};