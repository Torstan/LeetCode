/*
http://oj.leetcode.com/problems/largest-rectangle-in-histogram/
*/
#include <stack>
using std::stack;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = (int)height.size();
        if(n <= 0)
            return 0;
            
        stack<int> ids; //index in vector of height
        int max_area = 0;
        for(int i=0;i<n;i++)
        {
            while(!ids.empty() && height[ids.top()] > height[i])
            {
                int id = ids.top();
                ids.pop();
                int left = ids.empty() ? -1 : ids.top();
                int right = i;
                int area = (right - left - 1)*height[id];
                if(max_area < area)
                    max_area = area;
            }
            ids.push(i);
        }
        
        while(!ids.empty())
        {
            int id = ids.top();
            ids.pop();
            int left = ids.empty() ? -1 : ids.top();
            int right = n;
            int area = (right - left - 1)*height[id];
            if(max_area < area)
                max_area = area;
        }
        return max_area;
    }
};       
