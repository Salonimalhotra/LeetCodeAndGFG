class Solution
{
    public:
        int numSplits(string s)
        {
            int n = s.size();
            vector<int> prefix(n, 0);
            vector<int> suffix(n, 0);
            int totalAns = 0;
            int or_p = 0;
            for (int i = 0; i < s.size(); i++)
            {
                int pos = 1 << (s[i] - 'a');
                or_p = or_p | pos;
                prefix[i] = or_p;
            }

            or_p = 0;
            for (int i = s.size() - 1; i >= 0; i--)
            {
                int pos = 1 << (s[i] - 'a');
                or_p = or_p | pos;
                suffix[i] = or_p;
            }

            for (int k = 0; k <= s.size() - 2; k++)
            {
                int cnt1 = 0;
                int cnt2 = 0;
                for (int i = 0; i < 32; i++)
                {
                    int mask = 1 << i;
                    if (prefix[k] &mask) cnt1++;
                    if (suffix[k + 1] &mask) cnt2++;
                }
                if (cnt1 == cnt2)
                {
                    totalAns++;
                }
            }
          return totalAns;
        }
};