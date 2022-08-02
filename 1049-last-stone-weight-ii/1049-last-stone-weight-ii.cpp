#include<vector>
class Solution {
public:
    //logic is that we have to add + and - before stones and thus they get grouped into 2 groups s1 and s2 ,
     // we need to find the min diff between s1 group and s2 group we do this by finding if s2 can be formed through subset sum problem and then we we can get the diff between s2-s1 => totalSum-s1-s1 => totalSum-2*s1
    int lastStoneWeightII(vector<int>& stones) {
       int totalSum=0;
       for(int i=0;i<stones.size();i++){
           totalSum+=stones[i];
       }
       int n=stones.size();
       bool dp[n+1][totalSum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=totalSum;j++){
                if(i==0){
                    // if number of elements or size of array is 0 then we can't definately make up the totalSum
                    dp[i][j]=false;
                }
                if(j==0){
                    // if the sum required is 0 then we can definately make up by using null subset
                    dp[i][j]=true;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=totalSum;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        int diff=INT_MAX;
        for(int i=0;i<=totalSum/2;i++){
            if(dp[n][i]!=false){
                diff=min(diff,totalSum-(2 * i));
            }
        }
        return diff;
    }
};