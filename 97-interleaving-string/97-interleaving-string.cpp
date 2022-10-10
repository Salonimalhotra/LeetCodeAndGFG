class Solution
{
    public:
        bool solve(string s1, string s2, string s3, int n1, int n2, int n3, vector<vector < int>> &dp)
        {
            if (n3 == 0){
              if(n1==0 && n2==0) return 1;
              else{
                return 0;
              }
            }
          
            if (dp[n1][n2] != -1) return dp[n1][n2];
          
            int option1 = 0;
            int option2 = 0;
            if (n1 - 1 >= 0 && s1[n1 - 1] == s3[n3 - 1]) option1 = solve(s1, s2, s3, n1 - 1, n2, n3 - 1, dp);
            if (n2 - 1 >= 0 && s2[n2 - 1] == s3[n3 - 1]) option2 = solve(s1, s2, s3, n1, n2 - 1, n3 - 1, dp);
            dp[n1][n2] = option1 || option2;
            return dp[n1][n2];
        }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        return solve(s1, s2, s3, n1, n2, n3, dp);
    }
};