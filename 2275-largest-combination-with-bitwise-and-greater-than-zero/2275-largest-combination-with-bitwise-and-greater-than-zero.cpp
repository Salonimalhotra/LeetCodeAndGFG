class Solution
{
    public:
        int largestCombination(vector<int> &candidates)
        {
            int maxAns = 0;
            for (int i = 0; i < 32; i++)
            {
                int m = 1 << i;
                int cnt = 0;
                for (int j = 0; j < candidates.size(); j++)
                {
                    if ((candidates[j] & m) != 0) cnt++;
                }
                if(cnt>maxAns)maxAns=cnt;
            }
            
            return maxAns;
        }
};