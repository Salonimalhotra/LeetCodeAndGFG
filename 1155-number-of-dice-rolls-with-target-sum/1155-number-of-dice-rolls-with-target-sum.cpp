#include<bits/stdc++.h>
class Solution {
public:
//     int solve(int dices,int faces,int target){
//         if(target<0){
//             return 0;
//         }
//         if(dices==0 && target!=0){
//             return 0;
//         } 
//         if(dices!=0 && target==0){
//             return 0;
//         }
//         if(dices==0 && target==0){
//             return 1;
//         }
        
//         int mod=pow(10,9)+ 7;
//         long long ans=0;
//         for(int i=1;i<=faces;i++){
//             int temp=solve(dices-1,faces,target-i)%mod;
//             ans+=temp;
//         }
//         return ans%mod;
//     }
    
    int solveMemo(int dices,int faces,int target,vector<vector<int>>&dp){
         if(target<0){
            return 0;
        }
        if(dices==0 && target!=0){
            return 0;
        } 
        if(dices!=0 && target==0){
            return 0;
        }
        if(dices==0 && target==0){
            return 1;
        }
        
        if(dp[dices][target]!=-1){
            return dp[dices][target];
        }
        
        int ans=0;
        int mod=pow(10,9) + 7;
        for(int i=1;i<=faces;i++){
            int temp=((long int)(solveMemo(dices-1,faces,target-i,dp)))%mod;
            ans=(ans %mod + temp%mod)%mod;            
        }
        dp[dices][target]=ans;
        return dp[dices][target];        
    }
    int numRollsToTarget(int n, int k, int target) {
       // return solve(n,k,target);     
       vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solveMemo(n,k,target,dp);
    }
};