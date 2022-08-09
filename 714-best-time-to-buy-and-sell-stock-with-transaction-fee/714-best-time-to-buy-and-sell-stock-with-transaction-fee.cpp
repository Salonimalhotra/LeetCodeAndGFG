class Solution {
public:
     int tab(vector<int>&prices,int fee){
          int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2,0));      
        
         for(int i=n-1;i>=0;i--){
             for(int j=0;j<=1;j++){
                 int option1;
                 int option2;
                 if(j==1){
                     option1=prices[i] + dp[i+1][0] - fee;
                     option2=dp[i+1][1];
                 }
                 else if(j==0){
                     option1=-1 * prices[i] + dp[i+1][1];
                     option2 = dp[i+1][0];
                 }
                 dp[i][j]=max(option1,option2);
             }
         }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return tab(prices,fee);
    }
};