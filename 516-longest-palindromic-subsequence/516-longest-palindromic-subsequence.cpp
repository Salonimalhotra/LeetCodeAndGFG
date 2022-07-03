#include<algorithm>
#include<string>
class Solution {
public:
     int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        int ans[m+1][n+1];
        for(int i=0;i<=m;i++){
           ans[i][0]=0;
        }
        for(int j=1;j<=n;j++){
            ans[0][j]=0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    ans[i][j]=1+ans[i-1][j-1];
                }
                else{
                    int x=ans[i-1][j];
                    int y=ans[i][j-1];
                    ans[i][j]=max(x,y);
                }
            }
        }
        return ans[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string newstring=s;
        reverse(newstring.begin(),newstring.end());
        return longestCommonSubsequence(s, newstring);
        
        
    }
};