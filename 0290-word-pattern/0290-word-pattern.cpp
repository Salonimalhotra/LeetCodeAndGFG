class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            unordered_map<char, string> mp;
            int j = 0;
            unordered_map<string, char> mp1;
            for (int i = 0; i < pattern.size(); i++)
            {
                if(j==s.size()){
                  return false;
                }
                string st = "";
                while (j<s.size() && s[j] != ' ')
                {
                    st.push_back(s[j]);
                    j++;
                }
                if (mp1.find(st) != mp1.end())
                {
                    if (mp1[st] != pattern[i])
                    {
                        return false;
                    }
                }

                if (mp.find(pattern[i]) != mp.end())
                {
                    if (mp[pattern[i]] != st)
                    {
                        return false;
                    }
                }
                else
                {
                    mp[pattern[i]] = st;
                    mp1[st] = pattern[i];
                }
                if(j!=s.size())j++;
            }
            if(j!=s.size()) return false;
            return true;
        }
};