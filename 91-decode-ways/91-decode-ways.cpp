class Solution
{
    public:
        int helper(string s,int index,vector<int>&dp)
        {
            if (index==s.size()) return 1;

            else if (index==s.size()-1)
            {
                if (s[index] != '0') return 1;
                else return 0;
            }
             
           if(dp[index]!=-1) return dp[index];
          
            int ans;
            if (s[index] == '0') ans = 0;
            else
            {
                int num = (s[index] - '0') *10 + (s[index+1] - '0');
                if (num >= 1 && num <= 26)
                {
                    ans =helper(s,index+2,dp) + helper(s,index+1,dp);
                }
                else
                {
                    ans = helper(s,index+1,dp);
                }
            }

           return dp[index]=ans;
        }
    int numDecodings(string s) {   
      vector<int>dp(s.size(),-1);
      return helper(s,0,dp);      
    }
};