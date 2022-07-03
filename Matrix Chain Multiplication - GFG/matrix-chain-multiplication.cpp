// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int MCM(int arr[],int **dp,int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
            int tempAns=MCM(arr,dp,i,k)+MCM(arr,dp,k+1,j)+arr[i-1]* arr[k]* arr[j];
            if(tempAns<mn){
                mn=tempAns;
            }
        }
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int **dp=new int*[N+1];
        for(int i=0;i<=N;i++){
            dp[i]=new int[N+1];
            for(int j=0;j<=N;j++){
                dp[i][j]=-1;
            }
        }
        
        return MCM(arr,dp,1,N-1);
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends