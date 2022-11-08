class Solution
{
    public:
        vector<string> subdomainVisits(vector<string> &cpdomains)
        {
            vector<string> ans;
            unordered_map<string, int> mp;
            for (int i = 0; i < cpdomains.size(); i++)
            {
                string str = cpdomains[i];
                int rep = 0;
                int j = 0;
                while (str[j] != ' ')
                {
                    rep = rep *10 + (str[j] - '0');
                    j++;
                }
                j++;
                string str1 = "";
                string x = "";
                for (int k = j; k < str.size(); k++)
                {
                    str1.push_back(str[k]);
                }
                mp[str1] += rep;
                for (int m = str1.size() - 1; m >= 0; m--)
                {
                    if (str1[m] == '.')
                    {
                        string str2 = str1.substr(m + 1);
                        mp[str2] += rep;
                    }
                }
            }
            for (auto i: mp)
            {
                string x = "";
                x.append(to_string(i.second));
                x.push_back(' ');
                x.append(i.first);
                ans.push_back(x);
            }
            return ans;
        }
};