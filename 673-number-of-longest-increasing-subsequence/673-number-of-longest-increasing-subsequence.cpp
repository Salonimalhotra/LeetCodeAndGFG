class Solution
{
    public:
        int findNumberOfLIS(vector<int> &nums)
        {
            vector<int> dp(nums.size(), 1);
            vector<int> len(nums.size(), 0);
            int maxlen = 1;
            for (int i = 0; i < nums.size(); i++)
            {             
              
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] < nums[i])
                    {
                        if (dp[j] + 1 > dp[i])
                        {
                            dp[i] = dp[j] + 1;
                            maxlen = max(maxlen, dp[i]);
                            len[i] = len[j];
                        }
                        else if (dp[j] + 1 == dp[i])
                        {
                            len[i] += len[j];
                        }
                    }
                }
              if(dp[i]==1){
                len[i]=1;
              }
            }
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (dp[i] == maxlen)
                {
                    ans += len[i];
                }
            }

            return ans;
        }
};