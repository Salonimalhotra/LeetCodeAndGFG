#include<bits/stdc++.h>
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=1;
        int last=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=i-1;j>=0;j--){
                if((nums[i] % nums[j])==0 && dp[j] + 1>dp[i]){
                    dp[i]=dp[j] + 1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                last=i;
            }
        }
        
        
        vector<int>finalAns;
        finalAns.push_back(nums[last]);
        while(last!=hash[last]){
            last=hash[last];
            finalAns.push_back(nums[last]);
        }
        reverse(finalAns.begin(),finalAns.end());
        return finalAns;
    }
};