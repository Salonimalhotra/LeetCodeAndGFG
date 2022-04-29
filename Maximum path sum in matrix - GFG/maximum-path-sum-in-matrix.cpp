// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int rows=Matrix.size();
        int cols=Matrix[0].size();
        int dp[rows][cols];
        for(int j=0;j<cols;j++){
            dp[rows-1][j]=Matrix[rows-1][j];
        }
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(j==0){
                    dp[i][j]=Matrix[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
                }
                else if(j==cols-1){
                    dp[i][j]=Matrix[i][j]+max(dp[i+1][j-1],dp[i+1][j]);
                }
                else {
                    dp[i][j]=Matrix[i][j]+max(dp[i+1][j+1],max(dp[i+1][j],dp[i+1][j-1]));
                }
            }      
        }
        
        int max_ans=INT_MIN;
        for(int j=0;j<cols;j++){
            max_ans=max(dp[0][j],max_ans);
        }
        return max_ans;
      
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends