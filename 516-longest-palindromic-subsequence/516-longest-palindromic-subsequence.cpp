#include<string>
class Solution {
public:
    int lcs(string s,string s1){
        int n=s.size();
        int m=s1.size();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
           for(int j=0;j<=m;j++){
               if(i==0 || j==0){
                   dp[i][j]=0;
               }
           }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int x=dp[i-1][j];
                    int y=dp[i][j-1];
                    dp[i][j]=max(x,y);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string s1;
        for(int i=0;i<s.size();i++){
            s1.push_back(s[i]);
        }
        reverse(s1.begin(),s1.end());
        int lcs_num=lcs(s,s1);
        return lcs_num;
        
        
    }
};