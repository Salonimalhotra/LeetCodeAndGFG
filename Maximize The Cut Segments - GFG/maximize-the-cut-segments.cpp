// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int helper(int n,int * len,int size,int **dp){
      if(size==0){
          if(n==0){
              return 0;
          }
          else{
              return INT_MIN;
          }
      }
      else if(n==0){
          return 0;
      }
        else if(dp[size][n]!=-1){
            return dp[size][n];
        }
        
        if(len[size-1]<=n){
            int option1=helper(n-len[size-1],len,size,dp);
            if(option1!=INT_MIN){
                option1=1+option1;
            }
            int option2=helper(n,len,size-1,dp);
            dp[size][n]=max(option1,option2);
            return max(option1,option2);
        }
        else{
            return dp[size][n]=helper(n,len,size-1,dp);
        }
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int * len=new int[3];
        len[0]=x;
        len[1]=y;
        len[2]=z;
        int size=3;
        
        int ** dp=new int *[size+1];
        for(int i=0;i<=size;i++){
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
       
        int ans=helper(n,len,size,dp);
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends