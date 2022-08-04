class Solution {
public:
    int helperDP(vector<vector<char>>&matrix,int &maxi){
        int n=matrix.size();
        int m=matrix[0].size();
  
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        
        
       for(int i=n-1;i>=0;i--){
           for(int j=m-1;j>=0;j--){
               if(matrix[i][j]=='1'){
                   curr[j]=1 + min(next[j],min(curr[j+1],next[j+1]));
                   maxi=max(maxi,curr[j]);
               }
               else{
                   curr[j]=0;
               }
           }
           next=curr;
       }
        return next[0];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
         int maxi=0;
         int smallAns=helperDP(matrix,maxi);
        return maxi * maxi;
    }
};