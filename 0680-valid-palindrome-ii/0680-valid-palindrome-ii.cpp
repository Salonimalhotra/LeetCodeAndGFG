class Solution
{
    public:
        bool helper(string s, int start, int end)
        {
            while (start <= end)
            {
                if (s[start] == s[end])
                {
                    start++;
                    end--;
                }
                else if (s[start] != s[end])
                {
                    return false;
                }
            }
            return true;
        }
    bool validPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        int delCount = 0;
        while (start <= end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else if (s[start] != s[end])
            {
                if (delCount == 1)
                {
                    return false;
                }
                else
                {
                    if (helper(s, start + 1, end) == true)
                    {
                        delCount++;
                        start++;
                    }
                    else if (helper(s, start, end - 1) == true)
                    {
                        delCount++;
                        end--;
                    }
                    else {
                      return false;
                    }
                }
            }
        }
      return true;
    }
};