class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[amount+1];
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(j==0){
                    dp[i][j]=0;
                }
                if(i==0){
                    dp[i][j]=INT_MAX-1;
                }
            }
        }
        
        int i=1;
        for(int j=1;j<=amount;j++){
            if(j%coins[i-1]==0){
                dp[i][j]=j/coins[i-1];
            }
            else{
                dp[i][j]=INT_MAX-1;
            }
        }
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    int option1=1+dp[i][j-coins[i-1]];
                    int option2=dp[i-1][j];
                    dp[i][j]=min(option1,option2);
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