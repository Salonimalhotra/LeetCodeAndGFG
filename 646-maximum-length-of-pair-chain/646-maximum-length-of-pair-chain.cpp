#include<vector>
#include<algorithm>
class Solution {
public:
    
    static bool cmp(vector<int>&p1,vector<int>&p2){
        return p1[1]<p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size();
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                
            }
        }
       int best_ans=1;
        for(int i=0;i<n;i++){
            best_ans=max(best_ans,dp[i]);
        }
        return best_ans;
    }
};