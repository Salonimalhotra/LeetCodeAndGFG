// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N,string S,int i,int j,bool isTrue,int ***dp){
        int mod=pow(10,3)+3;
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue==true){
                if(S[i]=='T'){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                if(S[i]=='F'){
                    return 1;
                }
               else{
                   return 0;
               }
            }
        }
      
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        
        int finalAns=0;
        for(int k=i+1;k<=j-1;k+=2){
            int leftTrue=solve(N,S,i,k-1,true,dp);
            int leftFalse=solve(N,S,i,k-1,false,dp);
            int rightTrue=solve(N,S,k+1,j,true,dp);
            int rightFalse=solve(N,S,k+1,j,false,dp);
             if(S[k]=='|'){
                 if(isTrue ==true){
                  finalAns+=(leftTrue*rightFalse + leftTrue * rightTrue + leftFalse*rightTrue)%mod;
                 }
                 else{
                     finalAns+=(leftFalse * rightFalse)%mod;
                 }
             }
             else if(S[k]=='&'){
                  if(isTrue ==true){
                   finalAns+=(leftTrue * rightTrue)%mod;
                  }
                  else{
                      finalAns+=(leftTrue*rightFalse + leftFalse * rightFalse + leftFalse*rightTrue)%mod;
                  }
             }
             else if(S[k]=='^'){
                 if(isTrue==true){
                  finalAns+=(leftTrue * rightFalse + leftFalse*rightTrue)%mod;
                 }
                 else{
                    finalAns+=(leftFalse * rightFalse + leftTrue*rightTrue)%mod;
                 }
             }
            
        }
        
        dp[i][j][isTrue]=finalAns%mod;
        return finalAns%mod;
    }
    int countWays(int N, string S){
        // code here
      
        
        int ***dp=new int**[N];
        for(int i=0;i<N;i++){
            dp[i]=new int*[N];
            for(int j=0;j<N;j++){
                dp[i][j]=new int[2];
                for(int k=0;k<2;k++){
                    dp[i][j][k]=-1;
                    }
            }
        }
       
        return solve(N,S,0,N-1,true,dp);  
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends