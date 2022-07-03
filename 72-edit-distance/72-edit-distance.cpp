#include<string>
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[m+1];
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    // deleting the current character and telling recursion to bring leftover answer
                    int option1=dp[i-1][j];
                    // inserting the current character from word2 and telling recursion to bring leftover answer
                    int option2=dp[i][j-1];
                    //updating the current character at ith position thus teeling recursion to word over remaining leftover string word1 and word2;
                    int option3=dp[i-1][j-1];
                    dp[i][j]=1+min(option1,min(option2,option3));
                }
            }
        }
        return dp[n][m];
    }
};