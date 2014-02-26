/*
http://oj.leetcode.com/problems/maximal-rectangle/
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = (int)matrix.size();
        if(n == 0)
            return 0;
            
        //step 1
        vector<vector<int> > seq;
        seq.reserve(n);
        for(int i=0;i<n;i++)
        {
            const vector<char>& input = matrix[i];
            int col = (int)input.size();
            vector<int> row(col, 0);
            
            for(int j=0;j<col;j++)
            {
                if(input[j] == '0')
                {
                    row[j] = 0;
                }
                else
                {
                    int prev = j >= 1 ? row[j - 1] : 0;
                    row[j] = 1 + prev;
                }
            }
            seq.push_back(row);
        }
        
        //step 2
        int max_area = 0;
        for(int i=0;i<n;i++)
        {
            const vector<int>& row = seq[i];
            int col = (int)row.size();
            for(int j=0;j<col;j++)
            {
                if(row[j] == 0)
                    continue;
                vector<int> height;
                height.reserve(i+1);
                for(int k=i;k>=0;k--)
                {
                    if(seq[k][j] > 0)
                    {
                        height.push_back(seq[k][j]);
                    }
                    else
                        break;
                }
                int area = max_area_histogram(height);
                if(max_area < area)
                    max_area = area;
            }
        }
        return max_area;
    }
private:
    //the elements in height are all positive
    int max_area_histogram(const vector<int>& height)
    {
        int n = (int)height.size();
        if(n == 0)
            return 0;
        
        int max_area = 0;
        stack<int> index; //index of vector height
        for(int i=0;i<n;i++)
        {
            while(!index.empty() && height[index.top()] > height[i])
            {
                int id = index.top();
                index.pop();
                int left = index.empty() ? -1 : index.top();
                int right = i;
                int area = (right - left - 1)*height[id];
                if(max_area < area)
                    max_area = area;
            }
            index.push(i);
        }
        
        while(!index.empty())
        {               
            int id = index.top();
            index.pop();
            int left = index.empty() ? -1 : index.top();
            int right = n;
            int area = (right - left - 1)*height[id];
            if(max_area < area)
                max_area = area;
        }
        return max_area;
    }
};