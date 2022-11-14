class Solution
{
    public:
        int dp[100005];
        int helper(int low, int high, int zero, int one, int len)
        {
            if (len > high)
            {
                return 0;
            }
            if(dp[len]!=-1){
              return dp[len];
            }
            int ans = 0;
            if (len >= low && len <= high)
            {
                ans += 1;
            }

            int mod = pow(10, 9) + 7;
            int x = helper(low, high, zero, one, len + one);
            int y = helper(low, high, zero, one, len + zero);
            return dp[len]=((x + y )+ ans) % mod;
        }
    int countGoodStrings(int low, int high, int zero, int one)
    {
         memset(dp,-1,sizeof(dp));
        return helper(low, high, zero, one, 0);
    }
};