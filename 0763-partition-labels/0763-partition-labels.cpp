class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            vector<int> ans;
            vector<pair<int, int>> freq(26,
            {
                0,
                0 });
            int partitions = 0;
            for (int i = 0; i < s.size(); i++)
            {
                char ch = s[i];
                if (freq[ch - 'a'].first == 0)
                {
                    freq[ch - 'a'].first = i;
                    freq[ch - 'a'].second = i;
                }
                else
                {
                    freq[ch - 'a'].second = i;
                }
            }

            int maxAns = INT_MIN;
            int lower_bound = 0;

            for (int i = 0; i < s.size(); i++)
            {
                maxAns = max(freq[s[i] - 'a'].second, maxAns);
                if (maxAns == i)
                {
                    ans.push_back(i - lower_bound+1);
                    lower_bound=i+1;
                }
                else {
                  continue;
                }
            }
          return ans;
        }
};