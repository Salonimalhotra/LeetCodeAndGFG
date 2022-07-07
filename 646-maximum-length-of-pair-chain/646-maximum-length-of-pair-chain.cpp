#include<algorithm>
#include<vector>
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
         if(pairs.size()==1){
             return 1;
         }
         int n=pairs.size();
         int *dp=new int [n];
         dp[0]=1;
         for(int i=1;i<n;i++){
             dp[i]=1;
             for(int j=i-1;j>=0;j--){
                 if(pairs[i][0]>pairs[j][1]){
                     if(dp[j]+1>dp[i]){
                         dp[i]=1+dp[j];
                     }
                 }
             }
         }
        
        int maxAns=INT_MIN;
        for(int i=0;i<n;i++){
            maxAns=max(maxAns,dp[i]);
        }
        return maxAns;
         
    }
};