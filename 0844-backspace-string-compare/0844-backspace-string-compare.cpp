class Solution
{
    public:
        string helper(string s)
        {
            string s1 = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != '#')
                {
                    
                    s1.push_back(s[i]);
                }
                else
                {
                    if(s1.size()!=0) s1.pop_back();
                    continue;
                }
            }
            return s1;
        }
    bool backspaceCompare(string s, string t)
    {
        string s1 = helper(s);
        string s2 = helper(t);
        if (s1 == s2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};