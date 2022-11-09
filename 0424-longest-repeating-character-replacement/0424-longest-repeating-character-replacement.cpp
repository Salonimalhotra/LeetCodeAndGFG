class Solution
{
    public:
        int characterReplacement(string s, int k)
        {
            unordered_map<char, int> mp;
            int i = 0;
            int maxAns = INT_MIN;
            int j = 0;
            while (j < s.size())
            {
                mp[s[j]]++;
                int maxFreq = INT_MIN;
                for (auto i: mp)
                {
                    maxFreq = max(maxFreq, i.second);
                }
               
                while (j-i+1 - maxFreq > k)
                {
                    mp[s[i]]--;
                    i++;
                }
                maxAns = max(maxAns, j - i + 1);
               j++;
            }
            return maxAns;
        }
};