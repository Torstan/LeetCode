/*
http://oj.leetcode.com/problems/valid-palindrome/
*/
#include <string.h>
#define IS_ALPHANUM(x) (((x)<='z' && (x)>='a') || ((x)<='Z' && (x)>='A') || ((x)<='9' && (x)>='0'))
#define Is_ALPHA(x)  (((x)<='z' && (x)>='a') || ((x)<='Z' && (x)>='A'))

char to_upper(char x)
{
    if(((x)<='z' && (x)>='a')) 
        return x -('a' - 'A');
    else 
        return x;
}

class Solution {
public:
    bool isPalindrome(string s) {
        int n = strlen(s.c_str());
        if(n == 0)
        {
            return true;
        }
        const char* head = s.c_str();
        const char* tail = head + n-1;
        while(head <= tail)
        {
            if(!IS_ALPHANUM(*head))
                head++;
            else if(!IS_ALPHANUM(*tail))
                tail--;
            else
            {
                if(Is_ALPHA(*head) && Is_ALPHA(*tail) && to_upper(*head) == to_upper(*tail)) //all alpha
                {
                    head++;
                    tail--;
                }
                else if(!Is_ALPHA(*head) && !Is_ALPHA(*tail) && *head == *tail)  //all number
                {
                    head++;
                    tail--;
                }
                else
                    return false;
            }
        }
        return true;
    }
};