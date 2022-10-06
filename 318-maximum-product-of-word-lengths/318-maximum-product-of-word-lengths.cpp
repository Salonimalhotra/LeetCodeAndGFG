class Solution
{
    public:
       
        int maxProduct(vector<string> &words)
        {
            vector<int> helper;
            for (int i = 0; i < words.size(); i++)
            {

                string curr = words[i];
                int num = 0;              
                for (int j = 0; j < curr.size(); j++)
                {
                    char ch = curr[j];
                    int bit_pos = ch - 'a';
                    int mask = 1 << bit_pos;
                    num = num | mask;
                }
                helper.push_back(num);
            }

            int maxAns = INT_MIN;
            for (int i = 0; i < words.size(); i++)
            {
                for (int j = i + 1; j < words.size(); j++)
                {

                    if ((helper[i] & helper[j] )== 0)
                    {
                        int x = words[i].size() *words[j].size();
                        maxAns = max(maxAns, x);
                    }
                }
            }
            if (maxAns == INT_MIN) return 0;
            return maxAns;
        }
};