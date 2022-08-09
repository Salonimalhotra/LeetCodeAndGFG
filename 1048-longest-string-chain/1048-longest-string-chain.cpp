#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    bool static cmp(string a,string b){
        if(a.size()<b.size()){
            return true;
        }
        else{
            return false;
        }
    }
//     int lcs(string word1,string word2){
//         int n=word1.size();
//         int m=word2.size();
        
//         int **dp=new int*[n+1];
//         for(int i=0;i<=n;i++){
//             dp[i]=new int[m+1];
//             for(int j=0;j<=m;j++){
//                 dp[i][j]=0;
//             }
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1]==word2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
            
//         }
//         return dp[n][m];
//     }
  
    
    bool helper(string &a,string &b)
    {
        if(a.size()+1!=b.size()){
            return false;
        }
        
        int i=0;
        int j=0;
        while(j<b.size()){
            if(a[i]!=b[j]){
                j++;
            }
            else if(a[i]==b[j]){
                i++;
                j++;
            }
        }
        if(i==a.size() && j==b.size()){
            return true;
        }
        else{
            return false;
        }
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        // for(int i=0;i<words.size();i++){
        //     cout<<words[i]<<" ";
        // }
        // cout<<endl;
        int maxlen=1;
        vector<int>dp(words.size(),1);
        for(int i=1;i<words.size();i++){            
            for(int j=i-1;j>=0;j--){
                if(helper(words[j],words[i])==true && dp[j]+1>dp[i]){
                    dp[i]=dp[j] + 1;
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};