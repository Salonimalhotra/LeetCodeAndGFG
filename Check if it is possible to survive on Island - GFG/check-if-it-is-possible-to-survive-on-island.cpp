// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(M>=N){
            return -1;
        }
        if(S>=7){
          if(N*6<M*7){
            return -1;
          }    
        }
        
        int minDays=1;
        int food=N;
        int i=1;
        for(;i<=S;i++){
            if(food<M ){
                minDays++;
                food+=N;
            }
            food=food-M;
            
        }
        
        return minDays;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends