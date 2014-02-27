/*
problem: http://oj.leetcode.com/problems/length-of-last-word/
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s == NULL || *s == '\0')
            return 0;
        
        int n = strlen(s);
        const char* end = NULL;
        for(const char*p = s+n-1; p >= s; p--)
        {
            if(*p != ' ')
            {
                if(end == NULL)
                    end = p;
            }
            else
            {
                if(end != NULL)
                    return (int)(end - p);
            }
        }
        if(end != NULL)
            return (int)(end - s) + 1;
        else
            return 0;
    }
};