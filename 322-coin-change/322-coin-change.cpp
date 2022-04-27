#include<vector>
#include<climits>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=amount;j++){
            dp[0][j]=INT_MAX-1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    int x=dp[i-1][j];
                    int y=1+dp[i][j-coins[i-1]];
                    dp[i][j]=min(x,y);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount]==INT_MAX-1){
            return -1;
        }
        return dp[n][amount];
        
    }
};