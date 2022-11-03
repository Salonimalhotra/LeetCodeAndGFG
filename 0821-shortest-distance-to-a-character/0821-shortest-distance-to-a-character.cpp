class Solution
{
    public:
        vector<int> shortestToChar(string s, char c)
        {
            vector<int> ans;
            for (int i = 0; i < s.size(); i++)
            {
                int minDis = INT_MAX;
                for (int j = i; j >= 0; j--)
                {
                    if (s[j] == c)
                    {
                        minDis = min(minDis, i-j);
                        break;
                    }
                }
                for (int j = i; j < s.size(); j++)
                {
                    if (s[j] == c)
                    {
                        minDis = min(minDis, j - i);
                        break;
                    }
                }
              ans.push_back(minDis);
            }
          return ans;
        }
};