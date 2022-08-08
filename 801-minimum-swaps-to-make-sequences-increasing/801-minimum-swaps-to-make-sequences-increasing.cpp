#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,int index,bool swapped,vector<vector<int>>&dp){
        if(index==nums1.size()){
            return 0;
        }
        
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        
        if(swapped){
            swap(prev1,prev2);
        }
        
        int ans=INT_MAX;
        
        //prev1 and prev2 are not swapped and we arent swapping our elements at respective indexes 
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=min(ans,solve(nums1,nums2,index+1,0,dp));
        }
        
        if(nums1[index]>prev2 && nums2[index]>prev1){
               ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));
                  
        }
        
        return dp[index][swapped]=ans;        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return solve(nums1,nums2,1,swapped,dp);        
    }
};