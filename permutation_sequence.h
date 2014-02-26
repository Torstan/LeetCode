/*
http://oj.leetcode.com/problems/permutation-sequence/
*/
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s("");
        if(n <= 0 || k <= 0)
            return s;
            
        const int N = 10; 
        int perm[N] = {1};
        for(int i=1;i<sizeof(perm)/sizeof(perm[0]);i++)
        {
            perm[i] = perm[i-1] * i;
        }
        
        int id[N] = {0};
        int kk = k - 1; //0 based
        int i = 0;
        for(int m = n; m > 0; m--)
        {
            int d = kk/perm[m-1]; //0 based
            id[i++] = d;
            kk = kk%perm[m-1];
        }
        
        string str(n, '0');
        form_result(id, n, str);
        return str;
    }
private:
    int form_result(int* id, int n, string& s)
    {
        if(id == NULL || n < 1)
            return -1;
            
        vector<int> perm;
        perm.reserve(n);
        for(int i=0;i<n;i++)
            perm.push_back(i);
        
        for(int i=0;i<n;i++)
        {
            int a = id[i];
            std::swap(perm[i], perm[i + a]);
            std::sort(perm.begin()+i+1, perm.end());
        }
        for(int i=0;i<n;i++)
        {
            s[i] = (char)('1' + perm[i]);
        }
    }
};