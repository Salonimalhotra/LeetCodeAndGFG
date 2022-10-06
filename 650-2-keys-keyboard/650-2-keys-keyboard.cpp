class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[1]=0;
        for(int i=1;i<=n;i++){
          for(int j=2*i;j<=n;j+=i){
            dp[j]=min(dp[j], dp[i] + 1 + ((j/i) -1));
          }
        }
      return dp[n];
    }
};