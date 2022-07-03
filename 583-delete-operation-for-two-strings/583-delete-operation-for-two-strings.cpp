#include<string>
class Solution {
public:
    int lcs(string word1,string word2,int n,int m){
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[m+1];
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int LCS=lcs(word1,word2,word1.size(),word2.size());
        int minDistance=word1.size()-LCS + word2.size()-LCS;
        return minDistance;
    }
};