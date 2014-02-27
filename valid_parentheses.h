/*
problem: http://oj.leetcode.com/problems/valid-parentheses/
*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 0)
            return true;
        
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            char a = s[i];
            if(a == '(' || a == '[' || a == '{')
            {
                st.push(a);
            }
            else if(a == ')')
            {
                if(st.empty() || st.top() != '(')  
                    return false;
                st.pop();
            }
            else if(a == ']')
            {
                if(st.empty() || st.top() != '[')  
                    return false;
                st.pop();
            }
            else if(a == '}')
            {
                if(st.empty() || st.top() != '{')  
                    return false;
                st.pop();
            }
        }
        return st.empty() ? true : false;
    }
};