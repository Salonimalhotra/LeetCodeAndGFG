// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispalindrome(string str,int i,int j){
        bool ans=true;
        while(i<j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else{
                ans=false;
                break;
            }
        }
        return ans;
    }
    int solve(string str,int i,int j,int **dp){
        if(i>=j){
            return 0;
        }
        if(ispalindrome(str,i,j)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minAns=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int left;
            if(dp[i][k]!=-1){
                left=dp[i][k];
            }
            else{
                left=solve(str,i,k,dp);
            }
            int right;
            if(dp[k+1][j]!=-1){
                right=dp[k+1][j];
            }
            else{
                right=solve(str,k+1,j,dp);
            }
            int temp=left+right+1;
            minAns=min(temp,minAns);
            
        }
        return dp[i][j]=minAns;
    }
    int palindromicPartition(string str)
    {
        // code here
        int i=0;
        int j=str.length()-1;
        int **dp=new int*[str.length()];
        for(int i=0;i<str.length();i++){
            dp[i]=new int[str.length()];
            for(int j=0;j<str.length();j++){
                dp[i][j]=-1;
            }
        }
        return solve(str,i,j,dp);
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