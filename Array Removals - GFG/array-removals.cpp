// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int helper(vector<int>&a,int k,int s,int e,int **dp){
        if(a[e]-a[s]<=k){
            return 0; 
        }
        
        if(s>=e){
            return 0;
        }
        else if(dp[s][e]!=-1){
            return dp[s][e];
        }
        
        int option1=1+helper(a,k,s+1,e,dp);
        int option2=1+helper(a,k,s,e-1,dp);
        return dp[s][e]=min(option1,option2);
    }
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        int n=a.size();
        int **dp=new int *[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return helper(a,k,0,a.size()-1,dp);
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends