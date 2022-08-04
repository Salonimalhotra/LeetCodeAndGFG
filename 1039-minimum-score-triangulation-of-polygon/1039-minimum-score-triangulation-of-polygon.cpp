class Solution {
public:
    int partitionHelper(vector<int>&values,int i,int j,int **dp){
        if(i>=j){
            return 0;
        }
        
        if(j-i==1){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minAns=INT_MAX;
        for(int k=i+1;k<=j-1;k++){
            int left;
            int right;
           
            
            if(dp[i][k]!=-1){
                left=dp[i][k];
            }
            else{
                left=partitionHelper(values,i,k,dp);
            }
            
            if(dp[k][j]!=-1){
                right=dp[k][j];
            }
            else{
                right=partitionHelper(values,k,j,dp);
            }
            
             int tempAns=values[i] * values[k] * values[j] + left + right;
            
            if(tempAns<minAns){
                minAns=tempAns;
            }
        }
        return dp[i][j]=minAns;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int i=0;
        int j=values.size()-1;
        if(values.size()==3){
            int p=1;
            for(int i=0;i<=2;i++){
                p*=values[i];
            }
            return p;
        }
        int ** dp=new int *[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return partitionHelper(values,i,j,dp);
        
    }
};