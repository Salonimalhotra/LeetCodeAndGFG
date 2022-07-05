// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string str,int i,int j){
        if(i>=j){
            return true;
        }
        int s=i;
        int e=j;
        while(s<e){
            if(str[s]!=str[e]){
                return false;
            }
            else{
                s++;
                e--;
            }
        }
        return true;
    }
    int solve(string str,int i,int j,int **dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else if(isPalindrome(str,i,j)){
            return 0;
        }
        int minAns=INT_MAX;
        for(int k=i;k<=j-1;k++){
           int left;
         
           if(dp[i][k]!=-1){
               left=dp[i][k];
           }
           else{
               dp[i][k]=solve(str,i,k,dp);
               left=dp[i][k];
           }
             int right;
           if(dp[k+1][j]!=-1){
               right=dp[k+1][j];
           }
           else{
               dp[k+1][j]=solve(str,k+1,j,dp);
               right=dp[k+1][j];
           }
           int tempAns=1+left+right;
           if(tempAns<minAns){
               minAns=tempAns;
           }
        }
        
        return dp[i][j]=minAns;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        int **dp=new int *[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return solve(str,0,str.size()-1,dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends