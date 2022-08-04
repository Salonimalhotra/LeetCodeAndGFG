class Solution {
public:
    int helper(vector<int>&cost,int index,int *dp){
        if(index>=cost.size()){
            return 0;
        }       
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans1=cost[index] + helper(cost,index+2,dp);
        int ans2=cost[index]+helper(cost,index+1,dp);
        int smallAns=min(ans1,ans2);
        dp[index]=smallAns;
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int index1=0;
        int index2=1;
        int * dp=new int[cost.size()+1];
        for(int i=0;i<=cost.size();i++){
            dp[i]=-1;
        }
        return min(helper(cost,index1,dp),helper(cost,index2,dp));
    }
};