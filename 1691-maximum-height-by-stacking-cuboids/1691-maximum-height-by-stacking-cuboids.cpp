#include<bits/stdc++.h>
#include<algorithm>
class Solution {
public:    
   
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        int * dp=new int[n];
        dp[0]=cuboids[0][2];
        int maxheight=cuboids[0][2];
        for(int i=1;i<n;i++){
            dp[i]=cuboids[i][2];
            for(int j=i-1;j>=0;j--){
                if(cuboids[j][2]<=cuboids[i][2] && cuboids[j][0]<=cuboids[i][0] && cuboids[j][1]<=cuboids[i][1] && dp[j] + cuboids[i][2]>dp[i]){
                    dp[i]=cuboids[i][2]+ dp[j];
                }
            }
            maxheight=max(maxheight, dp[i]);
        }
       return maxheight;
    }
};