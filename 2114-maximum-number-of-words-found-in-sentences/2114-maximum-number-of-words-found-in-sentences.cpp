class Solution
{
    public:
        int mostWordsFound(vector<string> &sentences)
        {
            int maxAns = 0;
            for (int i = 0; i < sentences.size(); i++)
            {
                string s1 = sentences[i];
                int len = 0;
                for (int j = 0; j < s1.size(); j++)
                {
                    if (s1[j] == ' ')
                    {
                        len++;
                    }
                }
                len++;
                maxAns = max(maxAns, len);
            }
            return maxAns;
        }
};