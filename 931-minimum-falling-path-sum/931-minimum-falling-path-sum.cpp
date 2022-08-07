#include<vector>
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        int dir[3][2]={{1,1},{1,-1},{1,0}};
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int minAns=INT_MAX;
                for(int t=0;t<3;t++){
                    int x=i+dir[t][0];
                    int y=j+ dir[t][1];
                    if(x>=0 && y>=0 && x<n && y<n){
                        minAns=min(minAns,dp[x][y]);
                    }
                }
                dp[i][j]=matrix[i][j] + minAns;
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[0][j]);
        }
        
        return ans;
    }
};