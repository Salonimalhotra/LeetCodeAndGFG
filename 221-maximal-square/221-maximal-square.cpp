class Solution {
public:
    int  solve(vector<vector<char>>& matrix,int i,int j,int &maxi,int **dp){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0 ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=solve(matrix,i+1,j,maxi,dp);
        int right=solve(matrix,i,j+1,maxi,dp);
        int digonal=solve(matrix,i+1,j+1,maxi,dp);
        
        if(matrix[i][j]=='1'){
            int smallAns=1+ min(down,min(right, digonal));
            maxi=max(maxi,smallAns);
            return dp[i][j]=smallAns;
        }
        else{
            return dp[i][j]=0;
        }       
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int i=0;
        int j=0;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
           dp[i]=new int[m+1];
            for(int j=0;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        
        int ans=solve(matrix,i,j,maxi,dp);
        return maxi * maxi;       
        
    }
};