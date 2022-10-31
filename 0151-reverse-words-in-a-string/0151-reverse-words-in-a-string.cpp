class Solution
{
    public:
        string reverseWords(string s)
        {
            stack<string> st;
            string s1 = "";
            for (int i = 0; i < s.size();)
            {
                if (s[i] != ' ')
                {
                    s1.push_back(s[i]);
                    i++;
                }
                else
                {
                    if (s1 != "") st.push(s1);
                    s1 = "";
                    while (i < s.size() && i + 1 < s.size() && s[i] == ' ' && s[i + 1] == ' ')
                    {
                        i++;
                    }
                    if (i < s.size() && i + 1 < s.size() && s[i] == ' ' && s[i + 1] != ' ')
                    {
                        if (st.size() != 0) st.push(" ");
                        i++;
                    }
                    else
                    {
                        i++;
                    }
                }
            }

            if (s[s.size() - 1] != ' ')
            {
                st.push(s1);
            }
            string finalans = "";
            while (st.size() != 0)
            {
                finalans.append(st.top());
                st.pop();
            }
            return finalans;
        }
};