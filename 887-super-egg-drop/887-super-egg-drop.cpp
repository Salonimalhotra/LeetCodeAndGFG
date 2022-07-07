#include<climits>
class Solution {
public:
    int helper(int k,int n,int **dp){
        if(k==0){
            return 0;
        }
        else if(k==1){
            return n;
        }
        else if(n==0 || n==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        
        int minAns=INT_MAX;
        // for(int f=1;f<=n;f++){
        //     int option1=1+helper(k-1,f-1,dp);
        //     int option2=1+helper(k,n-f,dp);
        //     int tempAns=max(option1,option2);
        //     if(tempAns<minAns){
        //         minAns=tempAns;
        //     }
        // }
        // return minAns;
        int low=1;
        int high=n;
        while(low<=high){
            int mid=(low+(high-low)/2);
            int option1=1+helper(k-1,mid-1,dp);
            int option2=1+helper(k,n-mid,dp);
            int tempAns=max(option1,option2);
            if(tempAns<minAns){
                minAns=tempAns;
            }
            
            if(option2>option1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return dp[k][n]=minAns;
    }
    int superEggDrop(int k, int n) {
      int **dp=new int*[k+1];
        for(int i=0;i<=k;i++){
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        return helper(k,n,dp);
    }
};