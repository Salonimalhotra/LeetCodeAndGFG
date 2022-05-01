// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n][m];
       
        
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                int right_down=dp[i+1][j+1];
                int right_up=dp[i-1][j+1];
                int right=dp[i][j+1];
                if(i==0 || j==m-1){
                    right_up=0;
                }
                if(i==n-1 || j==m-1){
                    right_down=0;
                }
                if(j==m-1){
                    right=0;
                }
                dp[i][j]=M[i][j]+max(right,max(right_up,right_down));
                
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(dp[i][0],ans);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends