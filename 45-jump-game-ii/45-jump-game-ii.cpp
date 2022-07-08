#include<vector>
class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        if(n<=1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int * dp=new int [n];
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=INT_MAX;
           for(int j=0;j<i;j++){
               if(dp[j]!=INT_MAX && arr[j]+j>=i){
                   if(dp[j]+1<dp[i]){
                       dp[i]=dp[j]+1;
                }
             }
          }
        }
        if(dp[n-1]==INT_MAX){
            return -1;
        }
        return dp[n-1];
    }
};