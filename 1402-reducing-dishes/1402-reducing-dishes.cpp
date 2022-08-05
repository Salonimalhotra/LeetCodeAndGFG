#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int **dp=new int *[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[n+1];
        }
        for(int j=0;j<=n;j++){
            dp[n][j]=0;
        }
        for(int index=n-1;index>=0;index--){
            for(int timer=index;timer>=0;timer--){
                int incl=satisfaction[index] * (timer+1) + dp[index+1][timer+1];
                int excl=dp[index+1][timer];
                dp[index][timer]=max(incl,excl);
            }
        }
        
        return dp[0][0];
        
       
    }
};