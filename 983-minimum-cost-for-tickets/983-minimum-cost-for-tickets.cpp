class Solution {
public:
    int helper(vector<int>&days,vector<int>&costs,int n,int index,int *dp){
        if(index>=n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        //taking one day pass;
        int option1=costs[0]+helper(days,costs,n,index+1,dp);
        
        //taking 7 days pass;
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        
        int option2=costs[1] + helper(days,costs,n,i,dp);
        
        // taking 30 days pass
        int j;
        for(j=index;j<n && days[j]<days[index] + 30;j++);
        
        int option3=costs[2] + helper(days,costs,n,j,dp);
        
        return dp[index]=min(option1,min(option2,option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int index=0;
        int * dp=new int[n];
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        return helper(days,costs,n,0,dp);
    }
};